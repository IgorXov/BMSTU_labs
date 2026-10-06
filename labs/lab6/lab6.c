#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long num_d;
    double num_f;
} nums;

nums input_num() {
    nums n;
    double num;

    while (scanf("%lf", &num) != 1 || num < 0) {
        printf("Ошибка, введите положительное вещественное число: ");
        while (getchar() != '\n');
    }

    n.num_d = (long long)num;
    n.num_f = fabs(num - n.num_d);

    return n;
}

int input_char() {
    int ch;

    while (scanf("%d", &ch) != 1 || ch < 2 || ch > 16) {
        printf("Ошибка, введите основание от 2 до 16: ");
        while (getchar() != '\n');
    }

    return ch;
}

void num_sys_d(long long num, int ch) {
    int digits[100];
    int i = 0;

    if (num == 0) {
        printf("0");
        return;
    }

    while (num != 0) {
        digits[i] = num % ch;
        num /= ch;
        i++;
    }

    i--;

    while (i >= 0) {
        printf("%x", digits[i]);
        i--;
    }
}

void num_sys_fl(double num, int ch) {
    int i;
    int digit;

    if (num == 0) {
        return;
    }

    printf(".");

    for (i = 0; i < 10 && num > 0; i++) {
        num *= ch;
        digit = (int)num;

        printf("%x", digit);

        num -= digit;
    }
}

int main() {
    nums num;
    int ch;

    printf("Введите десятичное вещественное число: ");
    num = input_num();

    printf("Введите основание системы счисления (2-16): ");
    ch = input_char();

    printf("Результат: ");

    num_sys_d(llabs(num.num_d), ch);
    num_sys_fl(num.num_f, ch);

    printf("\n");

    return 0;
}