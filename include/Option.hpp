#pragma once
#include <vector>
#include <stdexcept>

enum class OptionType{
    Call = 1,
    Put = -1
};

class Option { 
    protected:
        double maturity_;
        double strike_;
        OptionType type_;
    public:
        virtual ~Option() = default;
        Option(double maturity, double strike, OptionType type)
            : maturity_(maturity), strike_(strike), type_(type)
        {
            if (strike_ <= 0.0) throw std::invalid_argument("Strike must be > 0");
                if (maturity_ < 0.0) throw std::invalid_argument("Maturity must be >= 0");
        }

        

        virtual double get_payoff(const std::vector<double>& path) const = 0;
        
        double get_maturity() const { return maturity_; }
        double get_strike() const { return strike_; }
        OptionType get_type() const { return type_; }
};