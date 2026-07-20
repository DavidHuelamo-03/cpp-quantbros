#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>

#define ASSERT_APPROX_EQUAL(val1, val2, tol) \
    do { \
        if (std::abs((val1) - (val2)) > (tol)) { \
            std::cerr << "Assertion failed: " << #val1 << " (" << (val1) \
                      << ") and " << #val2 << " (" << (val2) \
                      << ") differ by more than tolerance " << (tol) << std::endl; \
            std::exit(EXIT_FAILURE); \
        } \
    } while(0)

struct StandardMarketFixture {
    Environment env;
    double maturity = 1.0;
    double strike = 100.0;
    double spot = 100.0;
    double vol = 0.2;
    OptionType type = OptionType::Call;

    EuropeanOption option;
    Gbm gbm;

    StandardMarketFixture() 
        : option(maturity, strike, type),
          gbm(spot, vol, env) 
    {
        env.r = 0.05;
    }
};