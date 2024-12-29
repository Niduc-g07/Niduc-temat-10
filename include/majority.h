#include <math.h>

#define EPSILON 2

int double_equal(double a, double b) {
    return fabs(a - b) < EPSILON;
}

double majority_vote(double module1, double module2, double module3) {
    if (double_equal(module1, module2)) {
        return module1;  
    } else if (double_equal(module1, module3)) {
        return module1;  
    } else if (double_equal(module2, module3)) {
        return module2;  
    } else {
        return -1;  
    }
}

double abs_diff(double a, double b) {
    return fabs(a - b);
}


double three_domain_voters(double s1, double s2, double s3) {

    double d12 = abs_diff(s1, s2);
    double d23 = abs_diff(s2, s3);
    double d13 = abs_diff(s1, s3);

    if (d12 >= d23 && d12 >= d13) 
        return (s1 + s2) / 2.0;

    if (d23 >= d12 && d23 >= d13) 
        return (s2 + s3) / 2.0;
    
        
    return (s1 + s3) / 2.0;
    
}
