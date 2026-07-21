#include "testing.hpp"
#include "StandardShockGenerator.hpp"

static void test_fill_shocks_sizes() {
    StandardShockGenerator gen;
    std::vector<double> shocks1(100);
    std::vector<double> shocks2(0);

    gen.fill_shocks(shocks1);
    gen.fill_shocks(shocks2);

    ASSERT(shocks1.size() == 100);
    ASSERT(shocks2.size() == 0);
}

static void test_reset() {
    StandardShockGenerator gen;
    std::vector<double> shocks_run1(1000);
    std::vector<double> shocks_run2(1000);

    gen.reset(42);
    gen.fill_shocks(shocks_run1);

    gen.reset(42);
    gen.fill_shocks(shocks_run2);

    ASSERT(shocks_run1 == shocks_run2);
}

static void test_randomness() {
    StandardShockGenerator gen;
    std::vector<double> shocks_run1(1000);
    std::vector<double> shocks_run2(1000);

    gen.reset(42);
    gen.fill_shocks(shocks_run1);
    gen.fill_shocks(shocks_run2);

    ASSERT(shocks_run1 != shocks_run2);
}

static void test_normality() {
    StandardShockGenerator gen;
    std::vector<double> shocks(100000);

    gen.fill_shocks(shocks);

    double mean = 0;
    double variance = 0;

    for (size_t i = 0; i < shocks.size(); ++i) {
        mean += shocks[i];
    }
    mean /= shocks.size();

    for (size_t i = 0; i < shocks.size(); ++i) {
        variance += (shocks[i] - mean) * (shocks[i] - mean);
    }
    variance /= shocks.size() - 1;

    ASSERT_APPROX_EQUAL(0.0, mean, 0.01);
    ASSERT_APPROX_EQUAL(1.0, variance, 0.02);
}

int main() {
    TEST(test_fill_shocks_sizes);
    TEST(test_reset);
    TEST(test_randomness);
    TEST(test_normality);

    return 0;
}