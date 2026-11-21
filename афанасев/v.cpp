#include <stdio.h>

void count_digits(int n, int counts[]) {
    int number, i;
    for (i = 0; i < 10; i++) {
        counts[i] = 0;
    }

    printf("Введите %d натуральных чисел:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &number);
        while (number > 0) {
            counts[number % 10]++;
            number /= 10;
        }
    }
}

int main() {
    int n;
    int digit_counts[10];
    int i;

    printf("Введите количество чисел n: ");
    scanf("%d", &n);

    count_digits(n, digit_counts);

    printf("\nРезультат:\n");
    for (i = 0; i < 10; i++) {
        if (digit_counts[i] > 0) {
            printf("Цифра %d: %d\n", i, digit_counts[i]);
        }
    }

    return 0;
}