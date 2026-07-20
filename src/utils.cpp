#include "utils.hpp"

namespace utils{
    double compute_average(const std::vector<double>& vec){
        if (vec.empty()){
            return 0.0;
        }
        double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
        return sum / static_cast<double>(vec.size());
    }

    std::vector<double> scale_vector(std::vector<double>& vec, double factor){
        for (double& x : vec) {
        x *= factor;
        }
        return vec;
    }

    double normal_cdf(double x){
        return 0.5 * std::erfc(-x * M_SQRT1_2);
    }
}