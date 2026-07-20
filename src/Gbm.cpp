#include <vector>
#include "Gbm.hpp"

Gbm::Gbm(double s, double v, const Environment& e) : StochasticProcess(e), spot(s), vol(v) {}


std::vector<double> Gbm::generate_path(double maturity, int steps, std::mt19937& rng) const{
    double dt = maturity / static_cast<double> (steps); //time differential
    double drift = (e.r - 1.0/2.0 * vol*vol) * dt;
    double st_d = vol * std::sqrt(dt); // standard_deviation / integrated volatility
    std::vector<double> paths;
    paths.reserve(steps + 1);
    paths.push_back(spot);
    std::normal_distribution<double> dist(0.0,1.0);
    std::vector<double> shocks;
    shocks.reserve(steps);
    for (size_t i = 0; i < steps ; ++i){
        shocks.push_back(dist(rng));
        paths.push_back(paths[i] * std::exp(drift + st_d * shocks[i]));
    }

    return paths;
}

double Gbm::get_spot() const{
    return spot;
}

double Gbm::get_vol() const{
    return vol;
}