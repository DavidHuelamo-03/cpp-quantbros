#include "MonteCarloPricer.hpp"

MonteCarloPricer::MonteCarloPricer(int num_paths, int steps, unsigned int seed)
    : num_paths_(num_paths), steps_(steps), rng_(seed) {}

double MonteCarloPricer::run_mc(const Option& option, const StochasticProcess& process){
    std::vector<double> discounted_payoffs;
    discounted_payoffs.reserve(num_paths_);
    for (size_t i=0; i < num_paths_ ; i++){
        std::vector<double> path = process.generate_path(option.get_maturity(), steps_, rng_);
        discounted_payoffs.push_back(option.get_payoff(path));
    }
    discounted_payoffs = utils::scale_vector(discounted_payoffs, std::exp(-process.get_environment().r * option.get_maturity()));

    return utils::compute_average(discounted_payoffs);
}