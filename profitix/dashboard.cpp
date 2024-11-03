#include "precompiler.h"

void dashboard() {
    while (loggedIn) {
        clearScreen();  // Clear before showing the main menu

        // Display the main menu with dialog
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --no-cancel --menu \"Profitix Finance Manager\" 15 50 8 "
               "1 \"Add Income\" "
               "2 \"View Income\" "
               "3 \"Delete Income\" "
               "4 \"Add Expense\" "
               "5 \"View Expense\" "
               "6 \"Delete Expense\" "
               "7 \"Generate Report\" "
               "8 \"Budget Planning\" "
               "9 \"Delete Budget\" "
               "10 \"Log Out\" "
               "2> action_choice.txt");

        // Read user's menu choice from the dialog output file
        std::ifstream file("action_choice.txt");
        int choice;
        file >> choice;
        file.close();
        system("rm action_choice.txt");

        // Process menu choice
        switch (choice) {
            case 1: // Add Income
                clearScreen();
                addIncome();
                break;
            case 2: // View Income
                clearScreen();
                viewIncome(currentUserID);
                break;
            case 3: // Delete Income
                clearScreen();
                deleteIncome();
                break;
            case 4: // Add Expense
                clearScreen();
                addExpense();
                break;
            case 5: // View Expense
                clearScreen();
                viewExpense(currentUserID);
                break;
            case 6: // Delete Expense
                clearScreen();
                deleteExpense();
                break;
            case 7: // Generate Report
                clearScreen();
                generateReport(currentUserID);
                break;
            case 8: // Budget Planning
                clearScreen();
                budgetPlanning();
                break;
            case 9: // Log Out
                clearScreen();
                deleteBudget();
                break;
            case 10: // Log Out
                clearScreen();
            mainMenu();
            break;
            default: // Invalid Option
                clearScreen();  // Clear before displaying error message
                system("dialog --msgbox \"Invalid Option\" 6 30");
                break;
        }
    }
}