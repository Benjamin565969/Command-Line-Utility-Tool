#include "number_utils.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<double> data {1, 2, 3, 3, 3, 4, 5};

    try {
        SummaryStats stats = calcSummaryStats(data);

        std::cout << "Mean: "   << stats.mean   << '\n'
                  << "Median: " << stats.median << '\n'
                  << "Min: "    << stats.min    << '\n'
                  << "Max: "    << stats.max    << '\n';

        std::cout << "Mode(s): ";
        for (double m : stats.modes) { std::cout << m << ' '; }
        std::cout << '\n';

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error computing statistics: " << e.what() << '\n';
    }

    return 0;
}