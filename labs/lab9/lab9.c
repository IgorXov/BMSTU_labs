#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int matrix[8][8];
} Matrix;

typedef struct {
    int array[8];
} Scores;

Matrix make_matrix(void) {
    Matrix mat;
    int fir[3] = {0, 1, 3};
    int sec[3] = {3, 1, 0};
    for (int i = 0; i < 8; i++) {
        mat.matrix[i][i] = 0;
    }
    for (int i = 1; i <= 7; i++) {
        for (int j = 0; j <= i; j++) {
            int id = rand() % 3;
            if (i != j) {
                mat.matrix[j][i] = fir[id];
                mat.matrix[i][j] = sec[id];
            }
        }
    }
    return mat;
}

void result_matrix(Matrix mat) {
    printf("    ");
    for (int i = 1; i <= 8; i++) {
        printf("k%d  ", i);
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("k%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%3d ", mat.matrix[i][j]);
        }
        printf("\n");
    }
}

Scores scores_teams(Matrix mat) {
    Scores sc;
    for (int i = 0; i < 8; i++) {
        int s = 0;
        for (int j = 0; j < 8; j++) {
            s += mat.matrix[i][j];
        }
        sc.array[i] = s;
    }
    return sc;
}

void the_best_team(Matrix mat) {
    Scores scores = scores_teams(mat);
    int max = 0;
    for (int i = 0; i < 8; i++) {
        printf("Счёт у команды k%d равен: %d\n", i + 1, scores.array[i]);
        if (max < scores.array[i]) {
            max = scores.array[i];
        }
    }
    printf("Максимальное число очков равно: %d\n", max);
    printf("Команды, набравшие максимальное количество очков: ");
    for (int i = 0; i < 8; i++) {
        if (scores.array[i] == max) {
            printf("k%d ", i + 1);
        }
    }
}

int main() {
    srand((unsigned int)time(NULL));

    Matrix mat = make_matrix();
    result_matrix(mat);
    the_best_team(mat);
}