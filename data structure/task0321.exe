#include <stdio.h>
#define MAX_DEGREE 101

typedef struct {

    int degree;
    float coef[MAX_DEGREE];

}Polynomial;


void print_poly(Polynomial p, char str[])
{
    int i;

    printf("\t%s", str);

    for (i = 0; i < p.degree; i++) {
        printf("%5.1f x^%d ", p.coef[i], p.degree - i);
        if (p.coef[i + 1] > 0)
            printf("+");

    }
    printf("%4.1f\n", p.coef[p.degree]);
}

Polynomial read_poly()
{
    int i;
    Polynomial p;

    printf("다항식의 최고 차수 입력: ");
    scanf_s("%d", &p.degree);
    printf("각 항의 계수를 입력하시오 (총 %d개): ", p.degree + 1);

    for (i = 0; i <= p.degree; i++)
        scanf_s("%f", p.coef + i);

    return p;

}

Polynomial mult_poly(Polynomial a, Polynomial b)
{
    int i, j;
    Polynomial p;

    for (i = 0; i < a.degree + b.degree + 1; i++)
        p.coef[i] = 0;

    p.degree = a.degree + b.degree;

    for (i = 0; i < a.degree + 1; i++)
        for (j = 0; j < b.degree + 1; j++)
            p.coef[i + j] += a.coef[i] * b.coef[j];
    return p;
}

int main()
{
    int i;
    Polynomial x, y, b;

    x = read_poly();
    y = read_poly();
    b = mult_poly(x, y);
    print_poly(b, "X * Y = ");
    return 0;
}