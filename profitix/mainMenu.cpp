#include "precompiler.h"

void registerUser();
void loginUser();

void mainMenu() {
    loggedIn = false;

    // Main Menu for Register/Login
    while (!loggedIn) {
        clearScreen();
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --no-cancel --menu \"Profitix Finance Manager\" 15 50 3 1 \"Register\" 2 \"Login\" 3 \"Exit\" 2> menu_choice.txt");


        std::ifstream file("menu_choice.txt");
        file >> choice;
        file.close();
        system("rm menu_choice.txt");

        if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            clearScreen();
            loginUser();
        }
        else if (choice == 3) {
          exit(0);
        }
    }
}