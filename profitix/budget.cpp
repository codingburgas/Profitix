#include "precompiler.h"

// Function to set a monthly budget
void budgetPlanning() {
    std::string category, limit;

    system("dialog --inputbox \"Enter Category for Budget:\" 10 40 2> category.txt");
    std::ifstream file("category.txt");
    getline(file, category);
    file.close();

    system("dialog --inputbox \"Enter Budget Limit for the Category:\" 10 40 2> limit.txt");
    file.open("limit.txt");
    getline(file, limit);
    file.close();

    std::ofstream budget("budget.txt", std::ios::app);
    budget << category << " " << limit << "\n";
    budget.close();

    system("dialog --msgbox \"Budget Set Successfully!\" 6 30");
    system("rm category.txt limit.txt");
}