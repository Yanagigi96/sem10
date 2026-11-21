#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void swapPtr(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

void inputArray(double *ua, int n) {
    printf("Введите %d вещественных чисел:\n", n);
    for (double *p = ua; p < ua + n; ++p) {
        printf("Введите число: ");
        scanf("%lf", p);
    }
}

void printArray(double *ua, int n) {
    printf("Результат: ");
    for (double *p = ua; p < ua + n; ++p) {
        printf("%g ", *p);
    }
    printf("\n");
}

void processArray(double *ua, int n) {
    if (n <= 0) return;

    double minVal = *ua;
    double maxVal = *ua;
    for (double *p = ua + 1; p < ua + n; ++p) {
        if (*p < minVal) minVal = *p;
        if (*p > maxVal) maxVal = *p;
    }

    printf("Мин. элемент: %g, Макс. элемент: %g\n", minVal, maxVal);

    double *pos = ua;

    for (double *p = ua; p < ua + n; ++p) {
        if (*p == minVal) {
            swapPtr(p, pos);
            ++pos;
        }
    }

    for (double *p = pos; p < ua + n; ++p) {
        if (*p == maxVal) {
            swapPtr(p, pos);
            ++pos;
        }
    }
}

int main(void) {
    setlocale(LC_ALL, "Russian");

    int n;
    printf("Введите размер массива n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Размер должен быть положительным.\n");
        return 1;
    }

    double *ua = (double *)malloc(n * sizeof(double));
    if (ua == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    inputArray(ua, n);
    processArray(ua, n);
    printArray(ua, n);

    free(ua);
    return 0;
}