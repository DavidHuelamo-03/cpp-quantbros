#include "Option.hpp"
#include <algorithm>

class AmericanOption : public Option{
public:
    
        double getPayoff(const std::vector<double>& path) const override{
            int omega = static_cast<int>(type_);
            double payoff = std::max(omega * (path.back())-strike_, 0.0);
            return payoff;
        };
};