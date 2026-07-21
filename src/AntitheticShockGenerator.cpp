#include "AntitheticShockGenerator.hpp"
#include <stdexcept>

void AntitheticShockGenerator::reset(unsigned int seed){
    rng.seed(seed);
    generate_new_shocks = 1;
    last_shocks.clear();
}


double AntitheticShockGenerator::generate_shock(){
    return dist(rng);
}

void AntitheticShockGenerator::fill_shocks(std::vector<double>& shocks){   
    if (generate_new_shocks == 1){
        for (size_t i=0; i<shocks.size(); ++i){
        shocks[i] = generate_shock();
        }
        last_shocks = shocks;
        generate_new_shocks = 0;
    }else{
        if (shocks.size() != last_shocks.size()) {
            throw std::invalid_argument("Shock vector size must match the pending antithetic vector");
        }
        for (size_t i=0; i<shocks.size(); ++i){
        shocks[i] = -last_shocks[i];
        }
        generate_new_shocks = 1;
        last_shocks.clear();
    }
}