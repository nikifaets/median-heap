#include "Utils.h"
#include <math.h>

bool Utils::equal_eps(const float a, const float b){

    return fabs(a-b) < EPS;
}