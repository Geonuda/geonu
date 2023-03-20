#include <stdio.h>

double factorial_rec(double n) {
   if (n == 0) return 1; 
   else return n * factorial_rec(n - 1);
}

int main(void) {
   double n = 20;
   double result_rec = factorial_rec(n);
   printf("%lf! = %lf\n", n, result_rec);
   return 0;
}