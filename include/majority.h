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

float abs_diff(float a, float b) {
    return fabs(a - b);
}


float three_domain_voters(float s1, float s2, float s3) {

    float d12 = abs_diff(s1, s2);
    float d23 = abs_diff(s2, s3);
    float d13 = abs_diff(s1, s3);

    if (d12 >= d23 && d12 >= d13) {
        float (s1 + s2) / 2.0;
    } else if (d23 >= d12 && d23 >= d13) {
        float (s2 + s3) / 2.0;
    } else {
        float (s1 + s3) / 2.0;
    }
}
