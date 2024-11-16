void sort(float *a, float *b, float *c) {
    float temp;
    if (*a > *b) { temp = *a; *a = *b; *b = temp; }
    if (*b > *c) { temp = *b; *b = *c; *c = temp; }
    if (*a > *b) { temp = *a; *a = *b; *b = temp; }
}

float find_median_sorted(float a, float b, float c) {
    sort(&a, &b, &c);
    return b;  
}