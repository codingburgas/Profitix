#include "precompiler.h"

void dashboard() {
    while (loggedIn) {
        // Create a menu with an exit option at the bottom and a cancel option
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --no-cancel --menu \"Profitix Finance Manager\" 15 50 8 1 \"Add Income\" 2 \"View Income\" 3 \"Delete Income\" 4 \"Add Expense\" 5 \"View Expense\" 6 \"Delete Expense\" 7 \"Generate Report\" 6 \"Budget Planning\" 7 \"Log Out\" 2> action_choice.txt");

        std::ifstream file("action_choice.txt");
        int choice;
        file >> choice;
        file.close();
        system("rm action_choice.txt");

        switch (choice) {
            case 1:
                clearScreen();
            addIncome();
            break;
            case 2:
                clearScreen();
            viewIncome(currentUserID);
            break;
            case 3:
                clearScreen();
            deleteIncome(); // Call to delete income
            break;
            case 4:
                clearScreen();
            addExpense();
            break;
            case 5:
                clearScreen();
            viewExpense(currentUserID);
            break;
            case 6:
                clearScreen();
            deleteExpense(); // Call to delete expense
            break;
            case 7:
                clearScreen();
            generateReport();
            break;
            case 8:
                clearScreen();
            budgetPlanning();
            break;
            case 9:
                clearScreen();
            mainMenu();
            break;
            default:
                system("dialog --msgbox \"Invalid Option\" 6 30");
            break;
        }
    }
}
