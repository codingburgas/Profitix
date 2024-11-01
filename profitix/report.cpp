#include "precompiler.h"

// Function to generate a financial report
void generateReport() {
    std::ifstream income("income.txt"), expense("expense.txt");
    std::ofstream report("report.txt");
    std::string line;

    report << "----- Financial Report -----\n";
    report << "Income:\n";
    while (getline(income, line)) {
        report << line << "\n";
    }
    report << "\nExpenses:\n";
    while (getline(expense, line)) {
        report << line << "\n";
    }

    income.close();
    expense.close();
    report.close();

    system("dialog --textbox report.txt 20 50");
}