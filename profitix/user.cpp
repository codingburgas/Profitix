#include "precompiler.h"

// Function to register a new user
void registerUser() {
    std::string username, password;

    // Get username from user
    if (system("dialog  --backtitle \"Profitix Finance Manager — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --inputbox \"Enter Username:\" 10 40 2> username.txt") != 0) {
        system("rm username.txt");
        mainMenu();  // Call main menu on cancel
        return;
    }

    std::ifstream file("username.txt");
    getline(file, username);
    file.close();

    // Get password from user
    if (system("dialog --backtitle \"Profitix Finance Manager — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --passwordbox \"Enter Password:\" 10 40 2> password.txt") != 0) {
        system("rm username.txt password.txt");
        mainMenu();  // Call main menu on cancel
        return;
    }

    file.open("password.txt");
    getline(file, password);
    file.close();

    // Save user data
    std::ofstream users("users.txt", std::ios::app);
    users << username << " " << password << "\n";
    users.close();

    system("dialog --backtitle \"Profitix Finance Manager — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Registration Successful!\" 6 30");
    system("rm username.txt password.txt");
}

// Function to login a user
void loginUser() {
    std::string username, password, storedUser, storedPass;
    bool loginSuccess = false;

    // Get username from user
    if (system("dialog --backtitle \"Profitix Finance Manager — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --inputbox \"Enter Username:\" 10 40 2> username.txt") != 0) {
        system("rm username.txt");
        mainMenu();  // Call main menu on cancel
        return;
    }

    std::ifstream file("username.txt");
    getline(file, username);
    file.close();

    // Get password from user
    if (system("dialog --backtitle \"Profitix Finance Manager — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --passwordbox \"Enter Password:\" 10 40 2> password.txt") != 0) {
        system("rm username.txt password.txt");
        mainMenu();  // Call main menu on cancel
        return;
    }

    file.open("password.txt");
    getline(file, password);
    file.close();

    // Check if credentials match
    std::ifstream users("users.txt");
    while (users >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            loginSuccess = true;
            loggedIn = true;
            break;
        }
    }
    users.close();

    if (loginSuccess) {
        system("dialog --backtitle \"Profitix Finance Manager — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Login Successful!\" 6 30");
        dashboard();
    } else {
        system("dialog --backtitle \"Profitix Finance Manager — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Invalid Credentials!\" 6 30");
        loginUser();  // Restart login process
    }

    system("rm username.txt password.txt");
}
