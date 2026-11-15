#include <stdio.h>
#define N 10

void generate_matrix(int matrix[N][N]) {
    int top = 0, bottom = N - 1;
    int left = 0, right = N - 1;
    int n = 1;

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
}

void sum_lines(int matrix[N][N], int l_sum[N]) {
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j];
        }
        l_sum[i] = sum;
    }
}

void print_matrix(int matrix[N][N], int l_sum[N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("Сумма этой строки равна = %d \n", l_sum[i]);
    }
}


int main() {
    int matrix[N][N];
    int l_sum[N];

    generate_matrix(matrix);
    sum_lines(matrix, l_sum);

    print_matrix(matrix, l_sum);

    return 0;
}
