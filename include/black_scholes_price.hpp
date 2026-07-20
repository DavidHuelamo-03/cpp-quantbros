#include "Gbm.hpp"
#include "EuropeanOption.hpp"
#include "Environment.hpp"
using namespace std;

double black_scholes_price(Option& option, Gbm& gbm);