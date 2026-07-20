#pragma once

#include <vector>
#include <random>
#include <cmath>

#include "StochasticProcess.hpp"


class Gbm : public StochasticProcess{
private:
    double spot; // Value of the process at initial time
    double vol;
public:
    Gbm(double s, double v, const Environment& e);
    double get_spot() const;
    double get_vol() const;
    std::vector<double> generate_path(double maturity, int steps, std::mt19937& rng) const override;
};