#pragma once
#include "Option.hpp"
#include <algorithm>

class EuropeanOption : public Option{
public:

    EuropeanOption(double maturity, double strike, OptionType type)
    : Option(maturity, strike, type) {}


    double get_payoff(const std::vector<double>& path) const override{
        int omega = static_cast<int>(type_);
        double payoff = std::max(omega * (path.back())-strike_, 0.0);
        return payoff;
    };
    
};