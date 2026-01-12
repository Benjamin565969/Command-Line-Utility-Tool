#pragma once
#include "number_utils.h"
#include <string>
#include <map>
#include <vector>

void clearScreen();
void displayMenu();
void displayFrequencies(std::map<std::string, int> word_frequencies);
void displaySummaryStatistics(SummaryStats summary_statistics);

int getPrime();
std::vector<double> getData();
std::string getText();
std::string getPalindrome();

bool shouldExitApplication();