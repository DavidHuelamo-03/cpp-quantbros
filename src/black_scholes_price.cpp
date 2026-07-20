#include "black_scholes_price.hpp"
#include "utils.hpp"

double black_scholes_price(Option& option, Gbm& gbm){
    double spot = gbm.get_spot();
    double vol = gbm.get_vol();
    double maturity = option.get_maturity();
    double strike = option.get_strike();
    double r = gbm.get_environment().r;

    double numerator = log(spot/strike) + (r + 1/2 * vol * vol) * maturity;
    double denominator = vol * sqrt(maturity);

    double d1 = numerator / denominator;
    double d2 = d1 - denominator;

    normal_distribution<double> dist(0.0,1.0);

    return spot * utils::normal_cdf(d1) - strike * exp(-r * maturity)* utils::normal_cdf(d2);
}