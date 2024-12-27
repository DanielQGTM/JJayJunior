#include "Calc.h"

Calc::Calc() : value(0) {};
Calc::Calc(int val) : value(val) {};

int Calc::getValue() const
{
    return value;
};

void Calc::setValue(int val)
{
    value = val;
};

Calc Calc::operator+(const Calc &other) const
{
    return Calc(value + other.value);
};

Calc Calc::operator-(const Calc &other) const
{
    return Calc(value - other.value);
};

Calc Calc::operator*(const Calc &other) const
{
    return Calc(value * other.value);
};

Calc Calc::operator/(const Calc &other) const
{
    return Calc(value / other.value);
};