#include "precompiler.h"

void registerUser();
void loginUser();
void addIncome();
void viewIncome();
void addExpense();
void viewExpense();
void generateReport();
void budgetPlanning();

int main() {
    int choice;
    bool loggedIn = false;

    // Main Menu for Register/Login
    while (!loggedIn) {
        system("dialog --menu \"Welcome to Personal Finance Manager\" 15 50 3 1 \"Register\" 2 \"Login\" 3 \"Exit\" 2> menu_choice.txt");

        std::ifstream file("menu_choice.txt");
        file >> choice;
        file.close();
        system("rm menu_choice.txt");

        if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            loginUser();
            loggedIn = true;  // Assuming login is successful, for simplicity
        }
        else if (choice == 3) {
            return 0;  // Exit the program
        }
    }

    // Main Menu after login
    while (true) {
        // Create a menu with an exit option at the bottom and a cancel option
        system("dialog --menu \"Personal Finance Manager\" 15 50 8 1 \"Add Income\" 2 \"View Income\" 3 \"Add Expense\" 4 \"View Expense\" 5 \"Generate Report\" 6 \"Budget Planning\" 7 \"Cancel\" 8 \"Exit\" 2> action_choice.txt");

        std::ifstream file("action_choice.txt");
        file >> choice;
        file.close();
        system("rm action_choice.txt");

        switch (choice) {
            case 1:
                addIncome();
            break;
            case 2:
                viewIncome();
            break;
            case 3:
                addExpense();
            break;
            case 4:
                viewExpense();
            break;
            case 5:
                generateReport();
            break;
            case 6:
                budgetPlanning();
            break;
            case 7:
                // Cancel returns to the main menu
                    continue; // Goes back to the main menu
            case 8:
                return 0;  // Exit the program
            default:
                system("dialog --msgbox \"Invalid Option\" 6 30");
            break;
        }
    }


}