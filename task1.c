#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void inputArray(double *arr, int size, const char *name) {
    for (int i = 0; i < size; i++) {
        printf("%s[%d] = ", name, i);
        scanf("%lf", arr + i);  
    }
}


double calculateGamma(double *x, int n, double *y, int m) {
    double sx = 0, px = 1, A = 0, B = 0, C = 0;
    double sy = 0, py = 1, D = 0, E = 0, F = 0;

    
    for (int i = 0; i < n; i++) {
        sx += *(x + i);
        px *= *(x + i);
    }

   
    for (int i = 0; i < n; i++) {
        A += sx * (*(x + i)) * sin(*(x + i));
        B += px * (*(x + i)) * cos(*(x + i));
        C += (sx + px) * (*(x + i)) * tan(*(x + i));
    }


    for (int j = 0; j < m; j++) {
        sy += *(y + j);
        py *= *(y + j);
    }

  
    for (int j = 0; j < m; j++) {
        D += sx * (*(y + j)) * tan(*(y + j));
        E += px * (*(y + j)) * exp(*(y + j));
        F += (sx + px) * (*(y + j)) * cos(*(y + j));
    }

   
    double gamma = (A + B * cos(C)) / (D + E * sin(F));
    return gamma;
}

int main() {
    int n, m;
    printf("Введіть кількість елементів масиву x (n): ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву y (m): ");
    scanf("%d", &m);

    double *x = (double *)malloc(n * sizeof(double));
    double *y = (double *)malloc(m * sizeof(double));

    if (x == NULL || y == NULL) {
        printf("Помилка виділення пам'яті.\n");
        return 1;
    }

    printf("Введення масиву x:\n");
    inputArray(x, n, "x");
    printf("Введення масиву y:\n");
    inputArray(y, m, "y");

    double result = calculateGamma(x, n, y, m);
    printf("Результат γ = %lf\n", result);

    free(x);
    free(y);
    return 0;
}