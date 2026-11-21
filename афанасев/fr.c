#include <stdio.h>
#include <math.h>

int vvod_size() {
    int n;
    printf("Введите размер массива (0 для выхода): ");
    scanf("%d", &n);
    return n;
}

void vvod_massiva(int a[], int n) {
    printf("Введите числа через пробел:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void poisk_max_min(int a[], int n, int *mx, int *mn) {
    *mx = a[0];
    *mn = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > *mx) *mx = a[i];
        if (a[i] < *mn) *mn = a[i];
    }
}

int summa_na_nechetnih(int a[], int n) {
    if (n < 2) return 0;
    int min_el = a[1];
    for (int i = 1; i < n; i += 2) {
        if (a[i] < min_el) min_el = a[i];
    }
    int sum = 0;
    for (int i = 1; i < n; i += 2) {
        if (a[i] == min_el) sum += a[i];
    }
    return sum;
}

int max_para(int a[], int n, int *n1, int *n2) {
    if (n < 2) return 0;
    int max_s = a[0] + a[n - 1];
    *n1 = 0;
    *n2 = n - 1;
    for (int i = 1; i < n / 2; i++) {
        int s = a[i] + a[n - 1 - i];
        if (s > max_s) {
            max_s = s;
            *n1 = i;
            *n2 = n - 1 - i;
        }
    }
    return max_s;
}

int new_massiv(int a[], int n, int b[], float sr) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(a[i] - sr) < 0.0001) {
            b[k] = a[i];
            k++;
        }
    }
    return k;
}

void print_arr(int arr[], int size) {
    if (size == 0) {
        printf("пустой\n");
    } else {
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int a[100], b[100];

    while (1) {                          
        int n = vvod_size();
        if (n == 0) break;               

        vvod_massiva(a, n);
        printf("\n");

        int mx, mn;
        poisk_max_min(a, n, &mx, &mn);

        if (n < 2) {
            printf("Сумма минимальных на нечетных местах: невозможно определить\n");
        } else {
            printf("Сумма минимальных на нечетных местах: %d\n", summa_na_nechetnih(a, n));
        }

        int nom1, nom2;
        if (n < 2) {
            printf("Максимальная сумма пары: невозможно определить\n");
        } else {
            int max_s = max_para(a, n, &nom1, &nom2);
            printf("Максимальная сумма пары: %d (номера: %d и %d)\n", max_s, nom1, nom2);
        }

        float sr = (float)(mx + mn) / 2.0;
        printf("Среднее арифметическое макс и мин: %.2f\n", sr);

        int k = new_massiv(a, n, b, sr);
        printf("Новый массив: ");
        print_arr(b, k);
        printf("\n");
    }

    return 0;
}