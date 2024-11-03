#include "precompiler.h"

std::string currentUserID;

// Function to register a new user
void registerUser() {
    std::string username, password;

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Get username from user
    if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --inputbox \"Enter Username:\" 10 40 2> username.txt") != 0) {
        system("rm username.txt");
        clearScreen();
        mainMenu();  // Call main menu on cancel
        return;
    }

    std::ifstream file("username.txt");
    std::getline(file, username);
    file.close();

    // Check if username already exists
    bool userExists = false;
    std::ifstream usersFile("users.txt");
    std::string line;
    while (std::getline(usersFile, line)) {
        size_t firstQuote = line.find("\"");
        size_t secondQuote = line.find("\"", firstQuote + 1);

        if (firstQuote != std::string::npos && secondQuote != std::string::npos) {
            std::string storedUser = line.substr(firstQuote + 1, secondQuote - firstQuote - 1);
            if (storedUser == username) {
                userExists = true;
                break;
            }
        }
    }
    usersFile.close();

    if (userExists) {
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Username already exists! Please choose a different username.\" 6 40");
        clearScreen();
        registerUser();  // Restart registration process
        return;
    }

    // Get password from user
    if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --passwordbox \"Enter Password:\" 10 40 2> password.txt") != 0) {
        system("rm username.txt password.txt");
        clearScreen();
        mainMenu();  // Call main menu on cancel
        return;
    }

    file.open("password.txt");
    std::getline(file, password);
    file.close();

    // Validate username and password
    if (username.size() < 4 || username.size() > 25 || password.size() < 8) {
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Invalid Credentials!\" 6 30");
        clearScreen();
        registerUser();
    } else {
        // Generate a random 4-digit ID
        int userId = 1000 + std::rand() % 9000;

        std::ofstream users("users.txt", std::ios::app);
        users << "\"" << username << "\" \"" << password << "\" " << userId << "\n";
        users.close();
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Register Successful!\" 6 30");
        clearScreen();
    }

    system("rm username.txt password.txt");
}

// Function to login a user
void loginUser() {
    std::string username, password, storedUser, storedPass;
    bool loginSuccess = false;

    // Get username from user
    if (system("dialog --backtitle \"Profitix Finance Manager...\" --inputbox \"Enter Username:\" 10 40 2> username.txt") != 0) {
        system("rm username.txt");
        clearScreen();
        mainMenu();
        return;
    }

    std::ifstream file("username.txt");
    std::getline(file, username);
    file.close();

    // Get password from user
    if (system("dialog --backtitle \"Profitix Finance Manager...\" --passwordbox \"Enter Password:\" 10 40 2> password.txt") != 0) {
        system("rm username.txt password.txt");
        clearScreen();
        mainMenu();
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
                currentUserID = line.substr(line.size() - 4, line.size());
                loggedIn = true;
                break;
            }
        }
    }
    users.close();

    if (loginSuccess) {
        system("dialog --backtitle \"Profitix Finance Manager...\" --msgbox \"Login Successful!\" 6 30");
        clearScreen();
        dashboard();
    } else {
        system("dialog --backtitle \"Profitix Finance Manager...\" --msgbox \"Invalid Credentials!\" 6 30");
        clearScreen();
        loginUser();
    }

    system("rm username.txt password.txt");
}

// Function to handle forgot password
void forgotPasswordUser() {
    std::string username, newPassword, confirmPassword, storedUser, storedPass;
    bool userExists = false;

    // Get username for password reset
    if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --inputbox \"Enter Username for Password Reset:\" 10 40 2> username.txt") != 0) {
        system("rm username.txt");
        clearScreen();
        mainMenu();  // Return to main menu on cancel
        return;
    }

    std::ifstream file("username.txt");
    std::getline(file, username);
    file.close();
    system("rm username.txt");

    // Verify if username exists and prepare to update
    std::ifstream users("users.txt");
    std::ofstream temp("temp.txt");
    std::string line;

    while (std::getline(users, line)) {
        size_t firstQuote = line.find("\"");
        size_t secondQuote = line.find("\"", firstQuote + 1);
        size_t thirdQuote = line.find("\"", secondQuote + 1);
        size_t fourthQuote = line.find("\"", thirdQuote + 1);

        if (firstQuote != std::string::npos && secondQuote != std::string::npos &&
            thirdQuote != std::string::npos && fourthQuote != std::string::npos) {
            storedUser = line.substr(firstQuote + 1, secondQuote - firstQuote - 1);
            storedPass = line.substr(thirdQuote + 1, fourthQuote - thirdQuote - 1);

            if (storedUser == username) {
                userExists = true;

                // Get new password from user
                if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --passwordbox \"Enter New Password (min 8 chars):\" 10 40 2> password.txt") != 0) {
                    system("rm password.txt");
                    users.close();
                    temp.close();
                    system("rm temp.txt");
                    clearScreen();
                    mainMenu();  // Return to main menu on cancel
                    return;
                }

                std::ifstream pwdFile("password.txt");
                std::getline(pwdFile, newPassword);
                pwdFile.close();
                system("rm password.txt");

                // Confirm new password
                if (system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --passwordbox \"Confirm New Password:\" 10 40 2> confirm_password.txt") != 0) {
                    system("rm confirm_password.txt");
                    users.close();
                    temp.close();
                    system("rm temp.txt");
                    clearScreen();
                    mainMenu();  // Return to main menu on cancel
                    return;
                }

                std::ifstream confirmFile("confirm_password.txt");
                std::getline(confirmFile, confirmPassword);
                confirmFile.close();
                system("rm confirm_password.txt");

                // Check if passwords match and meet criteria
                if (newPassword != confirmPassword || newPassword.size() < 8) {
                    system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Passwords do not match or do not meet the criteria.\" 6 40");
                    clearScreen();
                    forgotPasswordUser();  // Restart forgot password process
                    return;
                }

                // Update the line with new password
                line = "\"" + storedUser + "\" \"" + newPassword + "\" " + line.substr(line.size() - 4, line.size());
            }
        }

        temp << line << "\n";
    }
    users.close();
    temp.close();

    if (userExists) {
        system("mv temp.txt users.txt");
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Password Reset Successful!\" 6 30");
    } else {
        system("rm temp.txt");
        system("dialog --backtitle \"Profitix Finance Manager — Use arrow keys and Enter to navigate — GitHub: https://github.com/codingburgas/finance-challenge-profitix\" --msgbox \"Username not found!\" 6 30");
        clearScreen();
        forgotPasswordUser();  // Restart forgot password process
    }

    clearScreen();
    mainMenu();
}
