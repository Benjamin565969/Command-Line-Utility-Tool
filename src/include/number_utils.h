#pragma once
#include <vector>

struct SummaryStats {
    double mean;
    double median;
    std::vector<double> modes;
    double min;
    double max;
};

SummaryStats calcSummaryStats(std::vector<double>& data);
bool isPrime(int num);