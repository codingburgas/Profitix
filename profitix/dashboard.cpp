
#include "precompiler.h"

void dashboard() {
    while (loggedIn) {
        // Create a menu with an exit option at the bottom and a cancel option
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --no-cancel --menu \"Profitix Finance Manager\" 15 50 8 1 \"Add Income\" 2 \"View Income\" 3 \"Add Expense\" 4 \"View Expense\" 5 \"Generate Report\" 6 \"Budget Planning\" 7 \"Log Out\" 2> action_choice.txt");

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
               viewIncome();
            break;
            case 3:
                clearScreen();
                addExpense();
            break;
            case 4:
                clearScreen();
                viewExpense();
            break;
            case 5:
                clearScreen();
               generateReport();
            break;
            case 6:
                clearScreen();
            // budgetPlanning();
            break;
            case 7:
                clearScreen();
            mainMenu();
            break;
            default:
                system("dialog --msgbox \"Invalid Option\" 6 30");
            break;
        }
    }
}
