#pragma once
#include "ShockGenerator.hpp"

class AntitheticShockGenerator : public ShockGenerator{
    public:
        void fill_shocks(std::vector<double>& shocks) override;
        void reset(unsigned int seed);
        int paths_per_group() const {
            return 2;
        }

    private:
        double generate_shock();
        std::mt19937 rng;
        std::normal_distribution<double> dist{0.0, 1.0};
        bool generate_new_shocks = 1;
        std::vector<double> last_shocks;
};