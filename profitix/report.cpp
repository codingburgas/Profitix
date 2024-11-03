#include "precompiler.h"

void generateReport(const std::string& currentUserID) {
    double totalIncome = 0.0;
    double totalExpense = 0.0;

    // Reading income data
    std::ifstream incomeFile("income.txt");
    if (incomeFile.is_open()) {
        std::string line;
        while (std::getline(incomeFile, line)) {
            if (line.size() < 4 || line.substr(line.size() - 4) != currentUserID) {
                continue;  // Skip entries that do not belong to the current user
            }
            line = line.substr(0, line.size() - 4);  // Remove userID

            size_t first_space = line.find(' ');
            size_t second_space = line.find(' ', first_space + 1);
            std::string amountStr = line.substr(second_space + 1);
            double amount = std::stod(amountStr);
            totalIncome += amount;  // Aggregate total income
        }
        incomeFile.close();
    } else {
        std::cout << "Error opening income file." << std::endl;
    }

    // Reading expense data
    std::ifstream expenseFile("expense.txt");
    if (expenseFile.is_open()) {
        std::string line;
        while (std::getline(expenseFile, line)) {
            if (line.size() < 4 || line.substr(line.size() - 4) != currentUserID) {
                continue;  // Skip entries that do not belong to the current user
            }
            line = line.substr(0, line.size() - 4);  // Remove userID

            size_t first_space = line.find(' ');
            size_t second_space = line.find(' ', first_space + 1);
            std::string amountStr = line.substr(second_space + 1);
            double amount = std::stod(amountStr);
            totalExpense += amount;  // Aggregate total expenses
        }
        expenseFile.close();
    } else {
        std::cout << "Error opening expense file." << std::endl;
    }

    // Calculate net profit/loss
    double netAmount = totalIncome - totalExpense;

    // Formatting the report
    std::ostringstream report;
    report << "---------------------\n";
    report << "   Financial Report   \n";
    report << "---------------------\n";
    report << std::fixed << std::setprecision(2);  // Set precision for monetary values
    report << "Total Income:  $" << totalIncome << "\n";
    report << "Total Expenses: $" << totalExpense << "\n";
    report << "Net Amount:    $" << netAmount << "\n";
    report << "---------------------\n";

    // Output the report
    clearScreen();  // Clear before displaying the report
    std::ofstream reportFile("financial_report.txt");
    reportFile << report.str();
    reportFile.close();

    // Show report to the user
    system("dialog --backtitle \"Profitix Finance Manager...\" --textbox financial_report.txt 10 40");

    // Clean up temporary report file
    system("rm financial_report.txt");
}