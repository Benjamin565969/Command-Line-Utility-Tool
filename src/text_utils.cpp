#include "text_utils.h"
#include <algorithm>
#include <cctype>
#include <map>
#include <string>
#include <sstream>

std::map<std::string, int> calcWordFrequencies(const std::string& input) {
    std::string text = input;

    // Convert to lowercase
    for (char& c : text) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }

    // Remove punctuation
    text.erase
    (
        std::remove_if(
            text.begin(), 
            text.end(), 
            [](unsigned char c) { return std::ispunct(c);}
            ),
        text.end()
    );

    std::stringstream ss(text);
    std::map<std::string, int> word_frequencies;

    std::string word;
    while (ss >> word) {
        word_frequencies[word]++;
    }

    return word_frequencies;
}

bool isPalindrome(const std::string& input) {
    auto left = input.begin();
    auto right = input.end();

    if (left == right) return true; // empty string

    --right; // move to last valid character

    while (left < right) {
        if (*left != *right) {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}