#include<math.h>

#define EPSILON 0.01

float Average(float* values, bool* isValid)
{
    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < 3; ++i) 
    {
        if (isValid[i]) 
        {
            sum += values[i];
            count++;
        }
    }

    return (count > 0) ? (sum / count) : 0.0;
}

double iterative_vote(float module1, float module2, float module3) 
{
    bool isValid[3] = {true, true, true}; 
    float values[3] = {module1, module2, module3};

    for (int i = 0; i < 3; ++i)
    {
        double mean = Average(values, isValid);
        
        bool stability = true;
        
        for (int i = 0; i < 3; ++i)
        {
            if (isValid[i] && fabs(values[i] - mean) > EPSILON) 
            {
                isValid[i] = false; 
                stability = false; 
            }
        }
        
        if (stability) break;
    }

    return Average(values, isValid);
}
