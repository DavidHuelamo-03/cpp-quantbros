#include <vector>
#include "Gbm.hpp"

Gbm::Gbm(double s, double v, const Environment& e) : StochasticProcess(e), spot(s), vol(v) {}

//TEST: Complete implementation: generate_path takes random shocks externally instead of generating them internally.
std::vector<double> Gbm::generate_path(double maturity, int steps, std::vector<double> shocks) const{
    double dt = maturity / static_cast<double> (steps); //time differential
    double drift = (e.r - 1.0/2.0 * vol*vol) * dt;
    double st_d = vol * std::sqrt(dt); // "standard_deviation" or "integrated volatility"


    std::vector<double> paths;
    paths.reserve(steps + 1);
    paths.push_back(spot);

    std::vector<double> shocks;
    shocks.reserve(steps);
    std::vector<double> factor(steps);

    for (size_t i = 0; i < steps; ++i){
        factor[i] = std::exp(drift + st_d * shocks[i]);
    }

    for (size_t i = 0; i < steps ; ++i){
        paths.push_back(paths.back() * factor[i]);
    }

    return paths;
}

double Gbm::get_spot() const{
    return spot;
}

double Gbm::get_vol() const{
    return vol;
}