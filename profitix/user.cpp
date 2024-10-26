#include "precompiler.h"

// Function to register a new user
void registerUser() {
    std::string username, password;

    // Get username from user
    system("dialog --inputbox \"Enter Username:\" 10 40 2> username.txt");
    std::ifstream file("username.txt");
    getline(file, username);
    file.close();

    // Get password from user
    system("dialog --passwordbox \"Enter Password:\" 10 40 2> password.txt");
    file.open("password.txt");
    getline(file, password);
    file.close();

    // Save user data
    std::ofstream users("users.txt", std::ios::app);
    users << username << " " << password << "\n";
    users.close();

    system("dialog --msgbox \"Registration Successful!\" 6 30");
    system("rm username.txt password.txt");
}

// Function to login a user
void loginUser() {
    std::string username, password, storedUser, storedPass;
    bool loginSuccess = false;

    // Get username from user
    system("dialog --inputbox \"Enter Username:\" 10 40 2> username.txt");
    std::ifstream file("username.txt");
    getline(file, username);
    file.close();

    // Get password from user
    system("dialog --passwordbox \"Enter Password:\" 10 40 2> password.txt");
    file.open("password.txt");
    getline(file, password);
    file.close();

    // Check if credentials match
    std::ifstream users("users.txt");
    while (users >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            loginSuccess = true;
            break;
        }
    }
    users.close();

    if (loginSuccess) {
        system("dialog --msgbox \"Login Successful!\" 6 30");
    }
    else {
        system("dialog --msgbox \"Invalid Credentials!\" 6 30");
        loginUser();
    }

    system("rm username.txt password.txt");
}