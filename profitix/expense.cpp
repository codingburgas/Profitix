#include "precompiler.h"

void addExpense() {
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

    // Add expense to file, appending currentUserID at the end
    std::ofstream expense("expense.txt", std::ios::app);
    expense << date << " " << category << " " << amount << " " << currentUserID << "\n";
    expense.close();

    // Confirmation message
    system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Expense Added Successfully!\" 6 30");
    system("rm date.txt category.txt amount.txt");
}

void viewExpense(const std::string& currentUserID) {
    std::ifstream file("expense.txt");
    std::string formattedData;

    // Set up table headers with fixed column widths
    formattedData = "Date           Category            Amount\n";
    formattedData += "---------------------------------------------\n";

    std::string line;
    while (std::getline(file, line)) {
        // Check if the last four characters match currentUserID
        if (line.size() < 4 || line.substr(line.size() - 4) != currentUserID) {
            continue;  // Skip this line if it does not match the current user's ID
        }

        // Remove last four characters (user ID) from the line
        line = line.substr(0, line.size() - 4);

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

    // Display formatted data in dialog
    system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --textbox formatted_expense.txt 20 50");

    // Clean up temporary file
    system("rm formatted_expense.txt");
}
