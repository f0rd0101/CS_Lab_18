#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void inputArray(double *arr, int size, const char *name) {
    for (int i = 0; i < size; i++) {
        printf("%s[%d] = ", name, i);
        scanf("%lf", arr + i);
    }
}


double calculateOmega(double *z, int n, double *beta, int m) {
    double sz = 0, pz = 1, A = 0, B = 0, C = 0;
    double sb = 0, pb = 1, D = 0, E = 0, F = 0;

   
    for (int i = 0; i < n; i++) {
        sz += *(z + i);
        pz *= *(z + i);
    }

   
    for (int i = 0; i < n; i++) {
        A += sz * (*(z + i)) * exp(*(z + i));
    }

 
    for (int i = 0; i < n; i++) {
        B += pz * (*(z + i)) * cos(*(z + i));
    }

  
    for (int i = 0; i < n; i++) {
        C += pz * (*(z + i)) * sin(*(z + i));
    }

    for (int i = 0; i < m; i++) {
        sb += *(beta + i);
        pb *= *(beta + i);
    }

    for (int i = 0; i < m; i++) {
        D += sb * (*(beta + i)) * sin(*(beta + i));
    }


    for (int i = 0; i < m; i++) {
        E += pb * (*(beta + i)) * tan(*(beta + i));
    }

    for (int i = 0; i < m; i++) {
        F += pb * (*(beta + i)) * fabs(*(beta + i));
    }

 
    double omega = (A + B * sin(C)) / (D + E + cos(F));
    return omega;
}

int main() {
    int n, m;
    printf("Введіть кількість елементів масиву z (n): ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву β (m): ");
    scanf("%d", &m);

    double *z = (double *)malloc(n * sizeof(double));
    double *beta = (double *)malloc(m * sizeof(double));

    if (z == NULL || beta == NULL) {
        printf("Помилка виділення пам'яті\n");
        return 1;
    }

    printf("Введення масиву z:\n");
    inputArray(z, n, "z");

    printf("Введення масиву β:\n");
    inputArray(beta, m, "β");

    double result = calculateOmega(z, n, beta, m);
    printf("Результат ω = %lf\n", result);

    free(z);
    free(beta);
    return 0;
}