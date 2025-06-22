#include <stdio.h>
#include <stdlib.h>
void importArray(int **array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap pha n tu [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}

int findMax(int **array, int rows, int cols) {
    int max = array[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    return max;
}

int findMin(int **array, int rows, int cols) {
    int min = array[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
        }
    }
    return min;
}

int main() {
    int rows, cols;
    int **array;

    printf("Nhap so hang (0 < rows < 1000): ");
    scanf("%d", &rows);
    printf("Nhap so cot (0 < cols < 1000): ");
    scanf("%d", &cols);

    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000) {
        printf("So hang hoac so cot khong hop le!\n");
        return 1;
    }

    array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    importArray(array, rows, cols);

    int max = findMax(array, rows, cols);
    int min = findMin(array, rows, cols);

    printf("Gia tri lon nhat: %d\n", max);
    printf("Gia tri nho nhat: %d\n", min);

    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
