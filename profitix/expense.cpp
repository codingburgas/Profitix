#include "precompiler.h"

// Function to add an expense record
void addExpense() {
    std::string date, category, amount;

    int day, month, year;

    // Prompt for Date with Calendar
    if (system("dialog --no-cancel --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --calendar \"Select Date:\" 0 0 2024 01 01 2> date.txt") != 0) {
        dashboard();
        return;
    }
    std::ifstream file("date.txt");
    file >> month >> day >> year;
    file.close();
    date = std::to_string(year) + "-" + (month < 10 ? "0" : "") + std::to_string(month) + "-" + (day < 10 ? "0" : "") + std::to_string(day);


    system("dialog --inputbox \"Enter Category:\" 10 40 2> category.txt");
    file.open("category.txt");
    getline(file, category);
    file.close();

    system("dialog --inputbox \"Enter Amount:\" 10 40 2> amount.txt");
    file.open("amount.txt");
    getline(file, amount);
    file.close();

    std::ofstream expense("expense.txt", std::ios::app);
    expense << date << " " << category << " " << amount << "\n";
    expense.close();

    system("dialog --msgbox \"Expense Added Successfully!\" 6 30");
    system("rm date.txt category.txt amount.txt");
}

// Function to view expense records
void viewExpense() {
    system("dialog --textbox expense.txt 20 50");
}