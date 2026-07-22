#pragma once
#include "ShockGenerator.hpp"


class StandardShockGenerator : public ShockGenerator{
    public:
        void fill_shocks(std::vector<double>& shocks) override;
        void reset(unsigned int seed);
        int paths_per_group() const {
            return 1;
        }

    private:
        double generate_shock();
        std::mt19937 rng;
        std::normal_distribution<double> dist{0.0, 1.0};
};