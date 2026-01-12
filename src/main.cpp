#include "gui_utils.h"
#include "number_utils.h"
#include "text_utils.h"
#include <iostream>
#include <map>
#include <vector>

int main() {
    bool running {true};

    do {
        clearScreen();
        displayMenu();

        int selection {-1};
        std::cin >> selection;

        switch (selection) {
            case 0:
                return 0;
            case 1: {
                int num = getPrime();
                bool result = isPrime(num);
                std::string output_msg = result ? "\nThis is a prime number!\n" : "\nThis is NOT a prime number.\n";
                std::cout << output_msg <<std::endl;
                break;
            }
            case 2: {
                std::vector<double> data = getData();
                SummaryStats summary_statistics = calcSummaryStats(data);
                displaySummaryStatistics(summary_statistics);
                break;
            }
            case 3: {
                std::string text = getText();
                std::map<std::string, int> word_frequencies = calcWordFrequencies(text);
                displayFrequencies(word_frequencies);
                break;
            }
            case 4: {
                std::string word = getPalindrome();
                bool result = isPalindrome(word);
                std::string output_msg = result ? "\nThis is a palindrome!\n" : "\nThis is NOT a palindrome.\n";
                std::cout << output_msg <<std::endl;
                break;
            }
        }
        running = shouldExitApplication();
    } while (running);

    return 0;
}