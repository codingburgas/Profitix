#include "precompiler.h"

void addIncome() {
    std::string date, category, amount;

    // Prompt for Date with Calendar
    if (system("dialog --no-cancel --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --calendar \"Select Date:\" 0 0 2024 01 01 2> date.txt") != 0) {
        dashboard();
        return;
    }

    // Read and format the date
    std::ifstream file("date.txt");
    std::string date_str;
    file >> date_str;  // Reads date in "MM-DD-YYYY" format
    file.close();
    date = date_str.substr(6, 4) + "-" + date_str.substr(0, 2) + "-" + date_str.substr(3, 2);

    // Prompt for Category
    if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --inputbox \"Enter Category:\" 10 40 2> category.txt") != 0) {
        dashboard();
        return;
    }
    file.open("category.txt");
    std::getline(file, category);
    file.close();

    // Prompt for Amount
    if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --inputbox \"Enter Amount:\" 10 40 2> amount.txt") != 0) {
        dashboard();
        return;
    }
    file.open("amount.txt");
    std::getline(file, amount);
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
