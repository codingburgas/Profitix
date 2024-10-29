#include "precompiler.h"

void addIncome() {
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

    // Prompt for Category
    if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --inputbox \"Enter Category:\" 10 40 2> category.txt") != 0) {
        dashboard();
        return;
    }
    file.open("category.txt");
    getline(file, category);
    file.close();

    // Prompt for Amount
    if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --inputbox \"Enter Amount:\" 10 40 2> amount.txt") != 0) {
        dashboard();
        return;
    }
    file.open("amount.txt");
    getline(file, amount);
    file.close();

    // Add income to file
    std::ofstream income("income.txt", std::ios::app);
    income << date << " " << category << " " << amount << "\n";
    income.close();

    // Confirmation message
    system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Income Added Successfully!\" 6 30");
    system("rm date.txt category.txt amount.txt");
}

void viewIncome() {
    system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --textbox income.txt 20 50");
}