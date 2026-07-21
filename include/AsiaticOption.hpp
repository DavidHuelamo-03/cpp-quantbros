#include "Option.hpp"
#include <algorithm>
#include <numeric>
#include <vector>

class AsiaticOption : public Option{
public:
    int omega = static_cast<int>(type_);
    std::vector<double> observationDates;

    double get_payoff(const std::vector<double>& path) const override{
        double sum = std::accumulate(path.begin(), path.end(), 0.0);
        double payoff = std::max(omega * (sum / path.size() - strike_), 0.0);
        return payoff;
    };
};