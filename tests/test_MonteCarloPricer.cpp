#include <iostream>
#include <iomanip>
#include "testing.hpp"
#include "Gbm.hpp"
#include "MonteCarloPricer.hpp"
#include "Utils.hpp"
#include "EuropeanOption.hpp"
#include "black_scholes_price.hpp"
#include "StandardShockGenerator.hpp"
#include "StandardMarketFixture.hpp"

static void test_call_price_matches_black_scholes() {
    StandardMarketFixture fx;

    const int num_paths = 100000;
    const int steps = 252;

    StandardShockGenerator gen;
    gen.reset(42);

    EuropeanOption option(fx.maturity, fx.strike, fx.type);
    Gbm gbm(fx.spot, fx.vol, fx.env);
    MonteCarloPricer pricer(num_paths, steps, gen);

    const double mc_price = pricer.run_mc(option, gbm);
    const double bs_price = black_scholes_price(option, gbm);

    ASSERT_APPROX_EQUAL(mc_price, bs_price, 0.1);
}


int main(){
    TEST(test_call_price_matches_black_scholes);
}