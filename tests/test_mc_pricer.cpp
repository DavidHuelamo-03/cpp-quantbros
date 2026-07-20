#include <iostream>
#include <iomanip>
#include "testing.hpp"
#include "Gbm.hpp"
#include "MonteCarloPricer.hpp"
#include "Utils.hpp"
#include "EuropeanOption.hpp"
#include "black_scholes_price.hpp"

static void test_mc_pricer(){
    Environment env;
    env.r = 0.05;

    double maturity = 1.0;
    double strike = 100.0;
    double spot = 100.0;
    OptionType type = OptionType::Call;

    EuropeanOption e_option(1.0, 100.0, OptionType::Call);

    double vol = 0.2;
    Gbm gbm(spot, vol, env);

    int numPaths = 100000;
    int steps = 252;
    MonteCarloPricer pricer(numPaths, steps);

    double mc_price = pricer.run_mc(e_option, gbm);
    double bs_price = black_scholes_price(e_option, gbm);

    ASSERT_APPROX_EQUAL(mc_price, bs_price, 0.1);
}

int main(){
    test_mc_pricer();
    std::cout << "All Monte Carlo pricer tests passed!" << std::endl;
    return 0;
}