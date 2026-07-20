#pragma once
#include <vector>
#include <numeric>
#include <cmath>

namespace utils {

    double compute_average(const std::vector<double>& vec);
    std::vector<double> scale_vector(std::vector<double>& vec, double factor);
    double normal_cdf(double x);
}