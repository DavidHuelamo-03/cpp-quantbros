#pragma once
#include <vector>
#include <random>

#include "Gbm.hpp"
#include "StochasticProcess.hpp"
#include "Option.hpp"
#include "Environment.hpp"
#include "Utils.hpp"

class MonteCarloPricer{
    private:
        int num_paths_;
        int steps_;
        std::mt19937 rng_;

    public:
        MonteCarloPricer(int num_paths, int steps, unsigned int seed = 42);

        double run_mc(const Option& option, const StochasticProcess& process);
        
};