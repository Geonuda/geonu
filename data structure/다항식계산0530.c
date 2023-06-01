#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DEGREE 100

void parse_poly(char *str, int poly[]) {
    int coeff, degree;

    while (*str) {
        sscanf(str, "%dx%d", &coeff, &degree);
        poly[degree] += coeff;

        while (*str && *str != '+') str++;
        if (*str == '+') str++;
    }
}

int main() {
    char input1[MAX_DEGREE], input2[MAX_DEGREE];
    int poly1[MAX_DEGREE] = {0}, poly2[MAX_DEGREE] = {0}, result[MAX_DEGREE] = {0};
    int max_degree = -1;

    printf("다항식 1 입력: ");
    fgets(input1, MAX_DEGREE, stdin);
    input1[strcspn(input1, "\n")] = 0;

    printf("다항식 2 입력: ");
    fgets(input2, MAX_DEGREE, stdin);
    input2[strcspn(input2, "\n")] = 0;

    parse_poly(input1, poly1);
    parse_poly(input2, poly2);

    for (int i = 0; i < MAX_DEGREE; i++) {
        result[i] = poly1[i] + poly2[i];
        if (result[i] != 0) max_degree = i;
    }

    if (max_degree < 0) {
        printf("결과 다항식: 0\n");
        return 0;
    }

    printf("결과 다항식: ");
    for (int i = max_degree; i >= 0; i--) {
        if (result[i] != 0) {
            if (i < max_degree) printf(" + ");
            printf("%dx%d", result[i], i);
        }
    }
    printf("\n");

    return 0;
}
