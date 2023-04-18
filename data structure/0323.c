#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col, i, j;
    int **matrix, **transpose;

    printf("행과 열의 크기를 입력하세요: ");
    scanf("%d %d", &row, &col);

    matrix = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < row; i++) {
        matrix[i] = (int *)malloc(col * sizeof(int));
    }

    printf("0이 아닌 항의 숫자를 입력하세요: ");
    int nonzero;
    scanf("%d", &nonzero);

    printf("행, 열, 값의 쌍을 차례대로 입력하세요:\n");
    for (i = 0; i < nonzero; i++) {
        int r, c, v;
        scanf("%d %d %d", &r, &c, &v);
        matrix[r - 1][c - 1] = v;
    }

    transpose = (int **)malloc(col * sizeof(int *));
    for (i = 0; i < col; i++) {
        transpose[i] = (int *)malloc(row * sizeof(int));
    }

    for (i = 0; i < col; i++) {
        for (j = 0; j < row; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    printf("전치 행렬:\n");
    for (i = 0; i < col; i++) {
        for (j = 0; j < row; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}