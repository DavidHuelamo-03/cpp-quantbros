#include <iostream>
#include <iomanip>
#include "Gbm.hpp"
#include "MonteCarloPricer.hpp"
#include "Utils.hpp"
#include "EuropeanOption.hpp"

int main(){
    Environment env;
    env.r = 0.05;

    double maturity = 1.0;
    double strike = 100.0;
    double spot = 100.0;
    OptionType type = OptionType::Call;

    EuropeanOption e_option(1.0, 100.0, OptionType::Call);

    double vol = 0.2;
    Gbm gbm(spot, vol, env);

    int num_paths = 100000;
    int steps = 252;
    MonteCarloPricer pricer(num_paths, steps);

    double mc_price = pricer.run_mc(e_option, gbm);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "==========================================" << std::endl;
    std::cout << "Monte Carlo Price : " << mc_price << std::endl;
    std::cout << "Expected BS Price : ~10.4506" << std::endl;
    std::cout << "==========================================" << std::endl;

    return 0;
}