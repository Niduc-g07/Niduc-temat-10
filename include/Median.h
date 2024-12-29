void sort(double *a, double *b, double *c) {
    double temp;
    if (*a > *b) { temp = *a; *a = *b; *b = temp; }
    if (*b > *c) { temp = *b; *b = *c; *c = temp; }
    if (*a > *b) { temp = *a; *a = *b; *b = temp; }
}

double find_median_sorted(double a, double b, double c) {
    sort(&a, &b, &c);
    return b;  
}