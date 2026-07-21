#include "StandardShockGenerator.hpp"

void StandardShockGenerator::fill_shocks(std::vector<double>& shocks){ //generate shocks distributed as a standard normal.
    for (size_t i=0; i<shocks.size(); ++i){
        shocks[i] = generate_shock();
    }
}

void StandardShockGenerator::reset(unsigned int seed){
    rng.seed(seed);
}


double StandardShockGenerator::generate_shock(){
    return dist(rng);
}

