void sort(double *a, double *b, double *c) {    //funckja sortująca rosnąco podane 3 wartości

    double temp;

    if(*a > *b){
        temp = *a; 
        *a = *b; 
        *b = temp;
    }

    if(*b > *c){
        temp = *b; 
        *b = *c; 
        *c = temp;
    }

    if(*a > *b){
        temp = *a; 
        *a = *b; 
        *b = temp;
    } 
}

double find_median_sorted(double a, double b, double c) {       //funkcja implementująca algorytm medianowy
                                                                //wynikiem tej funkcji jest mediana z pomiarów
    sort(&a, &b, &c);

    return b;  
}
