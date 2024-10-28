#include "precompiler.h"

// Function to register a new user
void registerUser() {
    std::string username, password;

    // Get username from user
    if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --inputbox \"Enter Username:\" 10 40 2> username.txt") != 0) {
        system("rm username.txt");
        mainMenu();  // Call main menu on cancel
        return;
    }

    std::ifstream file("username.txt");
    std::getline(file, username);
    file.close();

    // Get password from user
    if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --passwordbox \"Enter Password:\" 10 40 2> password.txt") != 0) {
        system("rm username.txt password.txt");
        mainMenu();  // Call main menu on cancel
        return;
    }

    file.open("password.txt");
    std::getline(file, password);
    file.close();

    if (username.size() < 4 || username.size() > 25 || password.size() < 8) {
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Invalid Credentials!\" 6 30");
        registerUser();
    } else {
        std::ofstream users("users.txt", std::ios::app);
        users << "\"" << username << "\" \"" << password << "\"\n";
        users.close();
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Register Successful!\" 6 30");
    }

    system("rm username.txt password.txt");
}

// Function to login a user
void loginUser() {
    std::string username, password, storedUser, storedPass;
    bool loginSuccess = false;

    // Get username from user
    if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --inputbox \"Enter Username:\" 10 40 2> username.txt") != 0) {
        system("rm username.txt");
        mainMenu();  // Call main menu on cancel
        return;
    }

    std::ifstream file("username.txt");
    std::getline(file, username);
    file.close();

    // Get password from user
    if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --passwordbox \"Enter Password:\" 10 40 2> password.txt") != 0) {
        system("rm username.txt password.txt");
        mainMenu();  // Call main menu on cancel
        return;
    }

    file.open("password.txt");
    std::getline(file, password);
    file.close();

    // Check if credentials match
    std::ifstream users("users.txt");
    std::string line;
    while (std::getline(users, line)) {
        size_t firstQuote = line.find("\"");
        size_t secondQuote = line.find("\"", firstQuote + 1);
        size_t thirdQuote = line.find("\"", secondQuote + 1);
        size_t fourthQuote = line.find("\"", thirdQuote + 1);

        if (firstQuote != std::string::npos && secondQuote != std::string::npos && thirdQuote != std::string::npos && fourthQuote != std::string::npos) {
            storedUser = line.substr(firstQuote + 1, secondQuote - firstQuote - 1);
            storedPass = line.substr(thirdQuote + 1, fourthQuote - thirdQuote - 1);

            if (storedUser == username && storedPass == password) {
                loginSuccess = true;
                loggedIn = true;
                break;
            }
        }
    }
    users.close();

    if (loginSuccess) {
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Login Successful!\" 6 30");
        dashboard();
    } else {
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Invalid Credentials!\" 6 30");
        loginUser();  // Restart login process
    }

    system("rm username.txt password.txt");
}
