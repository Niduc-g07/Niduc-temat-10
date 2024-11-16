#include <math.h>

#define EPSILON 0.01

int float_equal(float a, float b) {
    return fabs(a - b) < EPSILON;
}

float majority_vote(float module1, float module2, float module3) {
    if (float_equal(module1, module2)) {
        return module1;  
    } else if (float_equal(module1, module3)) {
        return module1;  
    } else if (float_equal(module2, module3)) {
        return module2;  
    } else {
        return -1;  
    }
}
