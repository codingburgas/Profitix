#include "precompiler.h"

void addExpense() {
    std::string date, category, amount;
    double totalAmountForCategory = 0;

    clearScreen();  // Clear before opening calendar dialog
    if (system("dialog --no-cancel --backtitle \"Profitix Finance Manager...\" --calendar \"Select Date:\" 0 0 2024 01 01 2> date.txt") != 0) {
        clearScreen();  // Clear before returning to dashboard
        dashboard();
        return;
    }

    std::ifstream file("date.txt");
    std::string date_str;
    file >> date_str;
    file.close();
    date = date_str.substr(6, 4) + "-" + date_str.substr(0, 2) + "-" + date_str.substr(3, 2);

    clearScreen();  // Clear before category input dialog
    if (system("dialog --backtitle \"Profitix Finance Manager...\" --inputbox \"Enter Category:\" 10 40 2> category.txt") != 0) {
        clearScreen();  // Clear before returning to dashboard
        dashboard();
        return;
    }
    file.open("category.txt");
    std::getline(file, category);
    file.close();

    double budgetLimit = getBudgetLimit(category);
    if (budgetLimit < 0) {
        clearScreen();  // Clear before error message
        system("dialog --msgbox \"No budget set for this category. Please set a budget first.\" 6 40");
        return;
    }

    std::ifstream expenseFile("expense.txt");
    std::string line, fileDate, fileCategory, fileAmount, fileUserID;
    while (std::getline(expenseFile, line)) {
        std::istringstream iss(line);
        iss >> fileDate >> fileCategory >> fileAmount >> fileUserID;

        if (fileCategory == category && fileUserID == currentUserID) {
            totalAmountForCategory += std::stod(fileAmount);
        }
    }
    expenseFile.close();

    double remainingBudget = budgetLimit - totalAmountForCategory;
    std::ostringstream formattedBudget;
    formattedBudget << std::fixed << std::setprecision(2) << remainingBudget;
    std::string budgetStr = formattedBudget.str();
    budgetStr.erase(budgetStr.find_last_not_of('0') + 1, std::string::npos);
    if (budgetStr.back() == '.') {
        budgetStr.pop_back();
    }

    std::string promptMessage = "Enter Amount:\n\n(Budget Remaining: " + budgetStr + ")";
    std::string dialogCommand = "dialog --backtitle \"Profitix Finance Manager...\" --inputbox \"" + promptMessage + "\" 10 40 2> amount.txt";

    clearScreen();  // Clear before amount input dialog
    if (system(dialogCommand.c_str()) != 0) {
        clearScreen();  // Clear before returning to dashboard
        dashboard();
        return;
    }
    file.open("amount.txt");
    std::getline(file, amount);
    file.close();

    double expenseAmount = std::stod(amount);

    if (totalAmountForCategory + expenseAmount > budgetLimit) {
        clearScreen();  // Clear before warning message
        system("dialog --msgbox \"Expense exceeds budget limit for this category!\" 6 40");
        return;
    }

    std::ofstream expense("expense.txt", std::ios::app);
    expense << date << " " << category << " " << amount << " " << currentUserID << "\n";
    expense.close();

    clearScreen();  // Clear before success message
    system("dialog --msgbox \"Expense Added Successfully!\" 6 30");
    system("rm date.txt category.txt amount.txt");
}

void viewExpense(const std::string& currentUserID) {
    clearScreen();  // Clear before displaying expenses

    std::ifstream file("expense.txt");
    std::string formattedData;

    formattedData = "Date           Category            Amount\n";
    formattedData += "---------------------------------------------\n";

    std::string line;
    while (std::getline(file, line)) {
        if (line.size() < 4 || line.substr(line.size() - 4) != currentUserID) {
            continue;
        }

        line = line.substr(0, line.size() - 4);
        size_t first_space = line.find(' ');
        size_t second_space = line.find(' ', first_space + 1);

        std::string date = line.substr(0, first_space);
        std::string category = line.substr(first_space + 1, second_space - first_space - 1);
        std::string amount = "$" + line.substr(second_space + 1);

        formattedData += date + std::string(15 - date.length(), ' ')
                      + category + std::string(20 - category.length(), ' ')
                      + amount + "\n";
    }
    file.close();

    std::ofstream tempFile("formatted_expense.txt");
    tempFile << formattedData;
    tempFile.close();

    clearScreen();  // Clear before displaying formatted data
    system("dialog --backtitle \"Profitix Finance Manager...\" --textbox formatted_expense.txt 20 50");

    system("rm formatted_expense.txt");
}

void deleteExpense() {
    std::string category, date, amount;

    clearScreen();  // Clear before category input for deletion
    if (system("dialog --inputbox \"Enter Expense Category to Delete:\" 10 40 2> category.txt") != 0) {
        clearScreen();  // Clear before returning to dashboard
        dashboard();
        return;
    }
    std::ifstream file("category.txt");
    std::getline(file, category);
    file.close();

    clearScreen();  // Clear before date input for deletion
    if (system("dialog --inputbox \"Enter Date of Expense to Delete (YYYY-MM-DD):\" 10 40 2> date.txt") != 0) {
        system("rm category.txt");
        clearScreen();  // Clear before returning to dashboard
        dashboard();
        return;
    }
    file.open("date.txt");
    std::getline(file, date);
    file.close();

    std::ifstream expenseFile("expense.txt");
    std::ofstream tempFile("temp_expense.txt");
    std::string line;
    bool deleted = false;

    while (std::getline(expenseFile, line)) {
        if (line.find(category) != std::string::npos && line.find(date) != std::string::npos) {
            deleted = true;
            continue;
        }
        tempFile << line << "\n";
    }

    expenseFile.close();
    tempFile.close();

    system("mv temp_expense.txt expense.txt");

    clearScreen();  // Clear before displaying delete result
    if (deleted) {
        system("dialog --msgbox \"Expense Deleted Successfully!\" 6 30");
    } else {
        system("dialog --msgbox \"No matching expense found!\" 6 30");
    }

    system("rm category.txt date.txt");
}