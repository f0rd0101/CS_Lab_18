#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void inputArray(double *arr, int size, const char *name) {
    for (int i = 0; i < size; i++) {
        printf("%s[%d] = ", name, i + 1);
        scanf("%lf", &arr[i]);
    }
}


void processAlpha(double *alpha, int n, double *A, double *B, double *C, double *s) {
    *A = 0;
    *B = 1;
    *C = 0;
    *s = 0;

    for (int i = 0; i < n; i++) {
        *s += alpha[i];
        *A += alpha[i] * tan(alpha[i]);
        *B *= alpha[i];
        *C += alpha[i] * sin(alpha[i]);
    }

    *A = (*s) * (*A);
    *C = (*s) * (*C);
}


void processBeta(double *beta, int m, double *D, double *E, double *F) {
    *D = 0;
    *E = 1;
    *F = 0;

    for (int i = 0; i < m; i++) {
        *D += beta[i] * cos(beta[i]);
        *E *= beta[i];
        *F += beta[i] * fabs(beta[i]);
    }
}

int main() {
    int n, m;

    printf("Введіть кількість елементів масиву α: ");
    scanf("%d", &n);
    double *alpha = (double *)malloc(n * sizeof(double));
    if (alpha == NULL) {
        printf("Помилка виділення памʼяті для масиву α.\n");
        return 1;
    }
    inputArray(alpha, n, "α");

    printf("Введіть кількість елементів масиву β: ");
    scanf("%d", &m);
    double *beta = (double *)malloc(m * sizeof(double));
    if (beta == NULL) {
        printf("Помилка виділення памʼяті для масиву β.\n");
        free(alpha);
        return 1;
    }
    inputArray(beta, m, "β");

    double A, B, C, D, E, F, s;
    processAlpha(alpha, n, &A, &B, &C, &s);
    processBeta(beta, m, &D, &E, &F);

    double denominator = D + E * sin(F);
    double omega;

    printf("\nРезультати:\n");
    printf("A = %.4lf\n", A);
    printf("B = %.4lf\n", B);
    printf("C = %.4lf\n", C);
    printf("D = %.4lf\n", D);
    printf("E = %.4lf\n", E);
    printf("F = %.4lf\n", F);
    printf("s = %.4lf\n", s);

    if (fabs(denominator) < 1e-6) {
        printf("Помилка: знаменник дорівнює нулю! Неможливо обчислити ω.\n");
    } else {
        omega = (A * cos(B) + C) / denominator;
        printf("ω = %.4lf\n", omega);
    }

    
    free(alpha);
    free(beta);

    return 0;
}
