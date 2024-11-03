#include "precompiler.h"

void addIncome() {
    std::string date, category, amount;

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

    clearScreen();  // Clear before amount input dialog
    if (system("dialog --backtitle \"Profitix Finance Manager...\" --inputbox \"Enter Amount:\" 10 40 2> amount.txt") != 0) {
        clearScreen();  // Clear before returning to dashboard
        dashboard();
        return;
    }
    file.open("amount.txt");
    std::getline(file, amount);
    file.close();

    double incomeAmount = std::stod(amount);

    std::ofstream income("income.txt", std::ios::app);
    income << date << " " << category << " " << amount << " " << currentUserID << "\n";
    income.close();

    clearScreen();  // Clear before success message
    system("dialog --msgbox \"Income Added Successfully!\" 6 30");

    system("rm date.txt category.txt amount.txt");
}

void viewIncome(const std::string& currentUserID) {
    clearScreen();  // Clear before displaying income

    std::ifstream file("income.txt");
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

    std::ofstream tempFile("formatted_income.txt");
    tempFile << formattedData;
    tempFile.close();

    clearScreen();  // Clear before displaying formatted income
    system("dialog --backtitle \"Profitix Finance Manager...\" --textbox formatted_income.txt 20 50");

    system("rm formatted_income.txt");
}

void deleteIncome() {
    std::string date, category, amount;

    clearScreen();  // Clear before input for deletion
    if (system("dialog --backtitle \"Delete Income\" --inputbox \"Enter Date, Category, and Amount (separated by spaces):\" 10 50 2> income_delete.txt") != 0) {
        clearScreen();  // Clear before returning to dashboard
        dashboard();
        return;
    }

    std::ifstream file("income_delete.txt");
    std::getline(file, date, ' ');
    std::getline(file, category, ' ');
    std::getline(file, amount);
    file.close();

    std::ifstream incomeFile("income.txt");
    std::ofstream tempFile("temp_income.txt", std::ios::app);
    std::string line;
    bool entryFound = false;

    while (std::getline(incomeFile, line)) {
        if (line.find(date) != std::string::npos && line.find(category) != std::string::npos && line.find(amount) != std::string::npos) {
            entryFound = true;
            continue;
        }
        tempFile << line << "\n";
    }

    incomeFile.close();
    tempFile.close();

    system("mv temp_income.txt income.txt");

    clearScreen();  // Clear before displaying delete result
    if (entryFound) {
        system("dialog --msgbox \"Income Entry Deleted Successfully!\" 6 30");
    } else {
        system("dialog --msgbox \"No matching entry found to delete.\" 6 30");
    }
}