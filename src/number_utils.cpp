#include "number_utils.h"
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <vector>

double calcMean(const std::vector<double>& data) {
    double total = std::accumulate(data.begin(), data.end(), 0.0);
    return total / static_cast<double>(data.size());
}

double calcMedian(const std::vector<double>& sorted_data) {
    int size = sorted_data.size();

    if (size % 2 == 0) {
        double left = sorted_data[size / 2 - 1];
        double right = sorted_data[size / 2];
        return (left + right) / 2.0;
    } 
    else {
        return sorted_data[size / 2];
    }
}

std::vector<double> calcMode(const std::vector<double>& data) {
    // The datapoint is the key and the datapoint's frequency is the value in the key-value pair
    std::map<double, int> freq;
    for (double x : data) {
        ++freq[x];
    }

    // A vector was used incase the dataset was multi-modal, meaning ties occur
    std::vector<double> modes;
    int highest_frequency = 0;

    for (const auto& [value, count] : freq) {
        if (count > highest_frequency) {
            highest_frequency = count;
            modes.clear();
            modes.push_back(value);
        } else if (count == highest_frequency) {
            modes.push_back(value);
        }
    }
    return modes;
}

SummaryStats calcSummaryStats(std::vector<double>& data) {
    if (data.empty()) {
        throw std::invalid_argument("calcSummaryStatistics: empty dataset");
    }

    std::sort(data.begin(), data.end());

    SummaryStats summary_statistics {
        calcMean(data),
        calcMedian(data),
        calcMode(data),
        data.front(),
        data.back()
    };

    return summary_statistics;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}