#include "rectifier.hpp"

double dod::math::rectifier(const double x) {
    return x>0 ? x : 0;
}

double dod::math::rectifierDerivative(double x) {
    return x>0 ? 1 : 0;
}
