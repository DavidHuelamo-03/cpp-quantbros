#include <iostream>
#include <iomanip>
#include "testing.hpp"
#include "Gbm.hpp"
#include "MonteCarloPricer.hpp"
#include "Utils.hpp"
#include "EuropeanOption.hpp"
#include "black_scholes_price.hpp"
#include "StandardShockGenerator.hpp"

static void test_call_price_matches_black_scholes() {
    Environment env;
    env.r = 0.05;

    const double maturity = 1.0;
    const double strike = 100.0;
    const double spot = 100.0;
    const double vol = 0.2;

    const int num_paths = 100000;
    const int steps = 252;

    StandardShockGenerator gen;
    gen.reset(42);

    EuropeanOption option(maturity, strike, OptionType::Call);
    Gbm gbm(spot, vol, env);
    MonteCarloPricer pricer(num_paths, steps, gen);

    const double mc_price = pricer.run_mc(option, gbm);
    const double bs_price = black_scholes_price(option, gbm);

    ASSERT_APPROX_EQUAL(mc_price, bs_price, 0.1);
}


int main(){
    TEST(test_call_price_matches_black_scholes);
}