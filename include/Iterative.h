#include<math.h>

#define EPSILON 2                           //definicja epsilonu (jednostka -> cm)

double Average(double* values, bool* isValid)       //funkcja licząca średnią z 
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

double iterative_vote(double module1, double module2, double module3)   //funkcja głosująca algorytmem iteracyjnym
                                                                        //program iteracyjnie odrzuca wyniki odbiegające od średniej
                                                                        //w większym stopniu niż wartość epsilon
                                                                        //jako wynik zwraca średnią z nieodrzuconych wyników
{
    bool isValid[3] = {true, true, true}; 
    double values[3] = {module1, module2, module3};

    for (int i = 0; i < 3; ++i)
    {
        double mean = Average(values, isValid);                         //średnia z nieodrzuconych wyników
        
        bool stability = true;
        
        for (int i = 0; i < 3; ++i)
        {
            if (isValid[i] && fabs(values[i] - mean) > EPSILON) 
            {
                isValid[i] = false;                                     //odrzuca wyniki odbiegające od średniej
                stability = false; 
            }
        }
        
        if (stability) break;                                           //jeżeli żaden wynik nie został odrzucony, kończy działanie funkcji
    }

    return Average(values, isValid);
}
