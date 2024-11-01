#include "precompiler.h"

void addIncome() {
    std::string date, category, amount;

    // Prompt for Date with Calendar
    if (system("dialog --no-cancel --backtitle \"Profitix Finance Manager\" --calendar \"Select Date:\" 0 0 2024 01 01 2> date.txt") != 0) {
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
    if (system("dialog --backtitle \"Profitix Finance Manager\" --inputbox \"Enter Category:\" 10 40 2> category.txt") != 0) {
        dashboard();
        return;
    }
    file.open("category.txt");
    std::getline(file, category);
    file.close();

    // Prompt for Amount
    if (system("dialog --backtitle \"Profitix Finance Manager\" --inputbox \"Enter Amount:\" 10 40 2> amount.txt") != 0) {
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
    system("dialog --backtitle \"Profitix Finance Manager\" --msgbox \"Income Added Successfully!\" 6 30");
    system("rm date.txt category.txt amount.txt");
}

void viewIncome() {
    std::ifstream file("income.txt");
    std::string formattedData;

    // Set up table headers with fixed column widths
    formattedData = "Date           Category            Amount\n";
    formattedData += "---------------------------------------------\n";

    std::string line;
    while (std::getline(file, line)) {
        size_t first_space = line.find(' ');
        size_t second_space = line.find(' ', first_space + 1);

        std::string date = line.substr(0, first_space);
        std::string category = line.substr(first_space + 1, second_space - first_space - 1);
        std::string amount = "$" + line.substr(second_space + 1);  // Add dollar sign to the amount

        // Format each entry with fixed column widths
        formattedData += date + std::string(15 - date.length(), ' ')  // Date column width: 15
                      + category + std::string(20 - category.length(), ' ')  // Category column width: 20
                      + amount + "\n";  // Amount column width: 10 (automatically fits as amount is last column)
    }
    file.close();

    // Write formatted data to a temporary file
    std::ofstream tempFile("formatted_income.txt");
    tempFile << formattedData;
    tempFile.close();

    // Display formatted data in dialog
    system("dialog --backtitle \"Profitix Finance Manager\" --textbox formatted_income.txt 20 50");

    // Clean up temporary file
    system("rm formatted_income.txt");
}
