#ifndef CALC_H
#define CALC_H
#include <iostream>

class Calc {

    private:                    //Private data member "value" of type int. Cannot
        int value;              //Can only be accessed via functions within class

    public:
        Calc();              // Default constructor
        Calc(int val);       // Parameterized constructor

        int getValue() const;   // Member function for getValue
        void setValue(int val); // Member function for setValue
        
        Calc operator+(const Calc& other) const;
        Calc operator-(const Calc& other) const;
        Calc operator*(const Calc& other) const;
        Calc operator/(const Calc& other) const;
};
#endif