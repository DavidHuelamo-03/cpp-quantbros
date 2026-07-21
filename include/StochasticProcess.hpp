#pragma once
#include <vector>
#include "Environment.hpp"

class StochasticProcess{
protected:
    const Environment& e;
public:
    explicit StochasticProcess(const Environment& env): e(env){}
    virtual ~StochasticProcess() = default;

    virtual std::vector<double> generate_path(double maturity, int steps, std::vector<double> shocks) const = 0;
    const Environment& get_environment() const {
        return e;
    }
};