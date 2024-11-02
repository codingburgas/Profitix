#include "precompiler.h"

// Function to set a monthly budget for a specific user and category
void budgetPlanning() {
    clearScreen();  // Clear screen at the beginning of the function

    std::string category, limit;

    // Prompt the user to enter a category with cancel handling
    clearScreen();
    if (system("dialog --inputbox \"Enter Category for Budget:\" 10 40 2> category.txt") != 0) {
        clearScreen();
        system("dialog --msgbox \"Budget setup cancelled.\" 6 30");
        return;  // Exit the function if cancelled
    }

    std::ifstream file("category.txt");
    getline(file, category);
    file.close();

    // Prompt the user to enter a budget limit with cancel handling
    clearScreen();
    if (system("dialog --inputbox \"Enter Budget Limit for the Category:\" 10 40 2> limit.txt") != 0) {
        clearScreen();
        system("dialog --msgbox \"Budget setup cancelled.\" 6 30");
        system("rm category.txt");  // Clean up temporary file
        return;  // Exit the function if cancelled
    }

    file.open("limit.txt");
    getline(file, limit);
    file.close();

    // Append the new budget entry with user ID to the budget file
    std::ofstream budget("budget.txt", std::ios::app);
    budget << category << " " << limit << " " << currentUserID << "\n";
    budget.close();

    clearScreen();
    // Notify the user that the budget has been set successfully
    system("dialog --msgbox \"Budget Set Successfully!\" 6 30");
    system("rm category.txt limit.txt");
}

// Function to retrieve the budget limit for a category specific to the logged-in user
double getBudgetLimit(const std::string& category) {
    clearScreen();  // Clear screen at the beginning of the function

    std::ifstream file("budget.txt");
    std::string line, budgetCategory, fileUserID;
    double limit = -1;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> budgetCategory >> limit >> fileUserID;

        // Check if the category and user ID match
        if (budgetCategory == category && fileUserID == currentUserID) {
            file.close();
            return limit;
        }
    }

    file.close();
    return -1;  // Return -1 if category not found for this user
}

// Function to set or update a budget for a specific category and user with cancel handling
void setBudget() {
    clearScreen();  // Clear screen at the beginning of the function

    std::string category;
    std::string amountStr;
    double amount;

    // Prompt for category with cancel handling
    clearScreen();
    if (system("dialog --inputbox \"Enter Category to Set Budget:\" 10 40 2> category.txt") != 0) {
        clearScreen();
        system("dialog --msgbox \"Budget setup cancelled.\" 6 30");
        dashboard();  // Return to dashboard on cancel
        return;
    }

    std::ifstream file("category.txt");
    std::getline(file, category);
    file.close();

    // Prompt for amount with cancel handling
    clearScreen();
    if (system("dialog --inputbox \"Enter Budget Amount:\" 10 40 2> amount.txt") != 0) {
        clearScreen();
        system("dialog --msgbox \"Budget setup cancelled.\" 6 30");
        system("rm category.txt");  // Clean up temporary file
        dashboard();
        return;
    }

    file.open("amount.txt");
    std::getline(file, amountStr);
    file.close();

    // Convert amount to double
    amount = std::stod(amountStr);

    // Open budget file in read mode to check if category already exists for this user
    std::ifstream budgetFile("budget.txt");
    std::ofstream tempFile("temp_budget.txt", std::ios::app);
    std::string line;
    bool budgetUpdated = false;

    while (std::getline(budgetFile, line)) {
        std::istringstream iss(line);
        std::string fileCategory, fileUserID;
        double fileBudget;

        iss >> fileCategory >> fileBudget >> fileUserID;

        // If matching category and user ID found, update the budget amount
        if (fileCategory == category && fileUserID == currentUserID) {
            tempFile << category << " " << amount << " " << currentUserID << "\n";
            budgetUpdated = true;
        } else {
            // Copy existing entry as-is
            tempFile << line << "\n";
        }
    }

    // If category does not exist for this user, add a new entry
    if (!budgetUpdated) {
        tempFile << category << " " << amount << " " << currentUserID << "\n";
    }

    budgetFile.close();
    tempFile.close();

    // Replace original budget file with updated file
    system("mv temp_budget.txt budget.txt");

    clearScreen();
    system("dialog --msgbox \"Budget Set Successfully!\" 6 30");
    system("rm category.txt amount.txt");
}
