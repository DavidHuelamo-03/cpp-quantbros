#pragma once
#include <vector>
#include <random>

#include "Gbm.hpp"
#include "StochasticProcess.hpp"
#include "Option.hpp"
#include "Environment.hpp"
#include "Utils.hpp"
#include "ShockGenerator.hpp"

class MonteCarloPricer{
    private:
        int num_paths_;
        int steps_;
        ShockGenerator& gen_;
        unsigned int seed = 42;

    public:
        //FIXME: It no longer takes unsigned int seed = 42 as argument
        MonteCarloPricer(int num_paths, int steps, ShockGenerator& gen);

        double run_mc(const Option& option, const StochasticProcess& process);
        
};