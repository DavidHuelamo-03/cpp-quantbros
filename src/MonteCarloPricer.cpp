#include "MonteCarloPricer.hpp"
#include <stdexcept>
#include <string>

MonteCarloPricer::MonteCarloPricer(int num_paths, int steps, ShockGenerator& gen)
    : num_paths_(num_paths), steps_(steps), gen_(gen) {
        if (num_paths_ % gen.paths_per_group() != 0) {
            throw std::invalid_argument("num_paths (" + std::to_string(num_paths_) + ") must be divisible by the generator group size (" + std::to_string(gen.paths_per_group()) + ")");
        }
    }

    //FIXME: Generate the shocks
double MonteCarloPricer::run_mc(const Option& option, const StochasticProcess& process){
    std::vector<double> discounted_payoffs;
    discounted_payoffs.reserve(num_paths_);
    std::vector<double> shocks;
    for (size_t i=0; i < num_paths_ ; i++){
        gen_.fill_shocks(shocks);
        std::vector<double> path = process.generate_path(option.get_maturity(), steps_, shocks);
        discounted_payoffs.push_back(option.get_payoff(path));
    }
    discounted_payoffs = utils::scale_vector(discounted_payoffs, std::exp(-process.get_environment().r * option.get_maturity()));

    return utils::compute_average(discounted_payoffs);
}