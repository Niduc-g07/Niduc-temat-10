#include <math.h>

#define EPSILON 2                           //definicja epsilonu (jednostka -> cm)

bool double_equal(double a, double b) {     //porównanie z uwzględnieniem epsilonu
    return fabs(a - b) < EPSILON;
}

double majority_vote(double module1, double module2, double module3) {      //funkcja głosująca algorytmem głosowania większościowego
                                                                            //w przypadku różnic pomiędzy odczytami większych od wartości
                                                                            //epsilon funkcja zwraca -1, sygnalizując brak wyboru

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

double abs_diff(double a, double b) {       //funkcja obliczająca wartość bezwzględną z różnicy wyników dwóch pomiarów
    return fabs(a - b);
}

double large_difference_rejection(double s1, double s2, double s3) {        //funkcja implementująca algorytm odrzucenia największej różnicy
                                                                            //algorytm ten odrzuca wynik najbardziej odbiegający od reszty
                                                                            //jako wynik zwraca średnią z pozostałych wyników

    double d12 = abs_diff(s1, s2);
    double d23 = abs_diff(s2, s3);
    double d13 = abs_diff(s1, s3);

    if (d12 >= d23 && d12 >= d13) 
        return (s1 + s2) / 2.0;

    if (d23 >= d12 && d23 >= d13) 
        return (s2 + s3) / 2.0;
    
        
    return (s1 + s3) / 2.0;
    
}
