#ifndef UTILS_H
#define UTILS_H

#include <complex>
#include <limits>

bool compare(double left, double right)
{
    return std::abs(left - right) < std::numeric_limits<double>::epsilon();
}

float compare(float left, float right)
{
    return std::abs(left - right) < std::numeric_limits<float>::epsilon();
}

#endif // UTILS_H
