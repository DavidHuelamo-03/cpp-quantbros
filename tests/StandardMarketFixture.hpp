#include "Environment.hpp" 
#include "EuropeanOption.hpp"
#include "Gbm.hpp"

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