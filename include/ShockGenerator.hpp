#pragma once
#include <vector>
#include <random>


class ShockGenerator{
    public:
        virtual ~ShockGenerator() = default;

        virtual void reset(unsigned int seed) = 0;

        virtual void fill_shocks(std::vector<double>& shocks) = 0; //fills a vector with shocks

        virtual int paths_per_group() const = 0;

    private:
        
};