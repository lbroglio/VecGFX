#include <stdlib.h>
#include "util.hpp"

bool compareWithEpsilon(float a, float b, float epsilon)
{
    return abs(a - b) < epsilon;
}