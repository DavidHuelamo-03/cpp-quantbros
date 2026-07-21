#include "black_scholes_price.hpp"
#include "testing.hpp"
#include "StandardMarketFixture.hpp"

void test_black_scholes_price(){
    StandardMarketFixture fx;
    double bs_price = black_scholes_price(fx.option, fx.gbm);
    ASSERT_APPROX_EQUAL(bs_price, 10.4506, 1e-3);
}

int main() {
    TEST(test_black_scholes_price);
    return 0;
}