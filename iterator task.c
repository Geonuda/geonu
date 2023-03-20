#include <stdio.h>

double factorial_iter(double n) {
    double result = 1; 
    for (double i = 1; i <= n; i++) { 
        result *= i;
    }
    return result;
}

int main(void) {
    double n = 20;
    double result_iter = factorial_iter(n);
    printf("%lf! = %lf\n", n, result_iter);
    return 0;
}