#include <stdio.h>
#include <math.h>

double f(double x) {
    return sin(x) - 2 * x * x + 10;
}

double find_root(double a, double b, double eps) {
    double c;

    while (b - a > eps) {
        c = (a + b) / 2;

        if (f(c) == 0)
            return c;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    return (a + b) / 2;
}

void twenty_zn(double a, double h) {
    double x;
    printf("Значение x  Значение f(x)\n");
    for (int i = 0; i < 20; i++) {
        x = a + i * h;
        printf("| %10.4f | %16.6f |\n", x, f(x));
    }
}

double input_eps() {
    double eps;
    while (scanf("%lf", &eps) == 0 || eps <= 0) {
        printf("Ошибка, введите точность (E): ");
        while (getchar() != '\n');
    }
    return eps;
}

int main(void) {
    double a = -10;
    double b = 0;
    double eps;
    double root;

    printf("Введите точность: ");
    eps = input_eps();

    if (f(a) * f(b) >= 0) {
        printf("На заданном отрезке нет гарантированного корня\n");
        return 1;
    }
    double h = (b - a) / 19.0;

    twenty_zn(a, h);

    root = find_root(a, b, eps);

    printf("Корень уравнения: %.10lf\n", root);
    printf("Значение функции: %.10lf\n", f(root));

    return 0;
}
