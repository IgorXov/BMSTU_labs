#include <stdio.h>

void generate_matrix() {
    int matrix[10][10];
    int top = 0, bottom = 9;
    int left = 0, right = 9;
    int n = 1;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = 0;
        }
    }
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            matrix[top][j] = n;
            n++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            matrix[i][bottom] = n;
            n++;
        }
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                matrix[bottom][j] = n;
                n++;
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = n;
                n++;
            }
            left++;
        }
    }
    for (int i = 0; i < 10; i++) {
        int s = 0;
        for (int j = 0; j < 10; j++) {
            s += matrix[i][j];
            printf("%3d ", matrix[i][j]);
        }
        printf("Сумма этой строки равна = %d \n", s);
    }
}

int main() {
    generate_matrix();
}
