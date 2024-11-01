#include "precompiler.h"

void addExpense() {
    std::string date, category, amount;

    // Prompt for Date with Calendar
    if (system("dialog --backtitle \"Profitix Finance Manager\" --calendar \"Select Date:\" 0 0 2024 01 01 2> date.txt") != 0) {
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
    system("dialog --inputbox \"Enter Category:\" 10 40 2> category.txt");
    file.open("category.txt");
    getline(file, category);
    file.close();

    // Prompt for Amount
    system("dialog --inputbox \"Enter Amount:\" 10 40 2> amount.txt");
    file.open("amount.txt");
    getline(file, amount);
    file.close();

    // Add expense to file
    std::ofstream expense("expense.txt", std::ios::app);
    expense << date << " " << category << " " << amount << "\n";
    expense.close();

    // Confirmation message
    system("dialog --msgbox \"Expense Added Successfully!\" 6 30");
    system("rm date.txt category.txt amount.txt");
}

void viewExpense() {
    std::ifstream file("expense.txt");
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
    std::ofstream tempFile("formatted_expense.txt");
    tempFile << formattedData;
    tempFile.close();

    // Display formatted data
    system("dialog --backtitle \"Profitix Finance Manager\" --textbox formatted_expense.txt 20 50");

    // Clean up temporary file
    system("rm formatted_expense.txt");
}
