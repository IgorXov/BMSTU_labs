#include <stdio.h>
#include <math.h>

void newNum(int num, int a) {
    int len = (int) floor(log10(abs(num))) + 1;
    if (num < 0) {
        a*=-1;
    }
    int new_n = a;
    int q = 2;
    new_n += num % 10 * pow(10,len);
    num/=10;
    while (num != 0) {
        if (q == len) {
            new_n += num % 10 * 10;
        } else {
            new_n += num % 10 * pow(10,q);
        }
        q++;
        num/=10;
    } 
    printf("%d %d", new_n, len);
}

int input() {
    int num;
    while (scanf("%d", &num) != 1) {
        printf("Ошибка, введите число: ");
        while (getchar() != '\n');
    }
    return num;
}
int input_char() {
    int a;
    while (scanf("%d", &a) != 1 || a > 10 || a < 0) {
        printf("Ошибка, введите цифру: ");
        while (getchar() != '\n');
    }
    return a;
}
int main(){
    int num, a;
    printf("Введите число: ");
    
    num = input();
    printf("Введите цифру: ");
    a = input_char();
    newNum(num,a);

}