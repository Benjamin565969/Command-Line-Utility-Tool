#include <number_utils.h>
#include <iostream>
#include <map>
#include <string>

void clearScreen() {
    // Terminal escape character 
    std::cout << "\033[2J\033[H";
}

void displayMenu() {
    std::cout
        << "CLI Utility Tool\n"
        << "================\n"
        << "0. Exit\n"
        << "1. Check if an integer is prime.\n"
        << "2. Calculate mean, mode, median, min, and max of a list.\n"
        << "3. Word frequency counter.\n"
        << "4. Check if a word is a palindrome (case sensitive).\n"
        << "\nSelect an option: ";
}

void displayFrequencies(std::map<std::string, int> word_frequencies) {
    std::cout << "\n";

    for (auto pair : word_frequencies) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    std::cout << "\n";
}

void displaySummaryStatistics(SummaryStats summary_statistics) {
    std::cout 
            << "Min : " << summary_statistics.min << "\n"
            << "Max : " << summary_statistics.max << "\n"
            << "Mean : " << summary_statistics.mean << "\n"
            << "Median : " << summary_statistics.median << "\n"
            << "Mode : ";

    for (auto mode : summary_statistics.modes) {
        std::cout << mode << ", ";
    }
    std::cout << "\n\n";
}

int getPrime() {
    int input {0};
    std::cout << "Please enter the integer you wish to check: ";
    std::cin >> input;
    return input;
}

std::vector<double> getData() {
    std::vector<double> data;
    std::string token;

    std::cout << "Enter numbers (q to finish):\n";

    while (true) {
        std::cout << "> " << std::flush;
        std::cin >> token;

        if (token == "q" || token == "Q") {
            break;
        }

        try {
            double value = std::stod(token);
            data.push_back(value);
        } catch (...) {
            std::cout << "Invalid input, try again.\n";
        }
    }

    return data;
}

std::string getText() {
    std::string text;
    std::cout << "Please enter the text you wish to check: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, text);
    return text;
}

std::string getPalindrome() {
    std::string input;
    std::cout << "Please enter the word you wish to check: ";
    std::cin >> input;
    return input;
}

bool shouldExitApplication() {
    bool should_exit {false};
    std::cout << "Enter '0' to exit the application or '1' to return to the main menu: ";
    std::cin >> should_exit;
    return should_exit;
}