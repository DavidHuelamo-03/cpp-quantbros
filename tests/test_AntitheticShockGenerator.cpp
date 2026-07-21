#include "AntitheticShockGenerator.hpp"
#include "testing.hpp"
#include <cmath>
#include <stdexcept>

static void test_consecutive_calls_are_antithetic(){
    AntitheticShockGenerator gen;
    std::vector<double> shocks1(100);
    std::vector<double> shocks2(100);
    gen.fill_shocks(shocks1);
    gen.fill_shocks(shocks2);
    for (size_t i = 0; i < shocks1.size(); ++i){
        ASSERT_APPROX_EQUAL(shocks1[i], -shocks2[i], 0.01);
    }
}

static void test_third_call_is_random(){//Testing the third call is not the opposite of the second one
    AntitheticShockGenerator gen;
    bool are_antithetic = true;

    std::vector<double> second_call(100);
    std::vector<double> third_call(100);
    gen.fill_shocks(second_call);
    gen.fill_shocks(second_call);
    gen.fill_shocks(third_call);

    for (size_t i = 0; i < second_call.size(); ++i) {
        if (std::abs(second_call[i] + third_call[i]) > 0.01) {
            are_antithetic = false;
            break;
        }
    }

    ASSERT(!are_antithetic);
}

static void test_reset(){
    AntitheticShockGenerator gen;
    gen.reset(42);
    std::vector<double> shocks1(100);
    std::vector<double> shocks2(100);
    gen.fill_shocks(shocks1);
    gen.fill_shocks(shocks2);

    gen.reset(42);
    std::vector<double> shocks3(100);
    std::vector<double> shocks4(100);
    gen.fill_shocks(shocks3);
    gen.fill_shocks(shocks4);
    for (size_t i = 0; i < shocks1.size(); ++i){
        ASSERT_APPROX_EQUAL(shocks1[i], shocks3[i], 0.01);
        ASSERT_APPROX_EQUAL(shocks2[i], shocks4[i], 0.01);
    }
}

static void test_empty_vector(){
    AntitheticShockGenerator gen;
    std::vector<double> shocks(0);
    gen.fill_shocks(shocks);
    ASSERT(shocks.size() == 0);
}

static void test_size_checking(){
    AntitheticShockGenerator gen;
    std::vector<double> first(100);
    std::vector<double> wrong_size(50);
    gen.fill_shocks(first);
    bool threw = false;
    try {
        gen.fill_shocks(wrong_size);
    }catch (const std::invalid_argument&){
        threw = true;
    }

    ASSERT(threw);
}

int main(){

    TEST(test_consecutive_calls_are_antithetic);
    TEST(test_third_call_is_random);
    TEST(test_reset);
    TEST(test_empty_vector);
    TEST(test_size_checking);

    return 0;
    
}