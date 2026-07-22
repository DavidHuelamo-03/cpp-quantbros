#pragma once
#include <vector>
#include <random>

#include "Gbm.hpp"
#include "StochasticProcess.hpp"
#include "Option.hpp"
#include "Environment.hpp"
#include "Utils.hpp"
#include "ShockGenerator.hpp"
#include "StandardShockGenerator.hpp"

class MonteCarloPricer{
    private:
        int num_paths_;  //Number of paths to be simulated
        int steps_;      //Number of steps in time for path
        ShockGenerator& gen_;
        unsigned int seed = 42;

    public:
        MonteCarloPricer(int num_paths, int steps, ShockGenerator& gen);

        double run_mc(const Option& option, const StochasticProcess& process);
        
};