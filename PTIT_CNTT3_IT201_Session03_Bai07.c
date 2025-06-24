#include <stdio.h>
#include <stdlib.h>

int tinhTongDongK(int **arr, int k, int cols) {
    int tong = 0;
    for (int j = 0; j < cols; j++) {
        tong += arr[k][j];
    }
    return tong;
}

int main() {
    int rows, cols, k;
    int **arr;

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 && cols <= 0) {
        printf("So hang va so cot khong hop le\n");
        return 0;
    } else if (rows <= 0) {
        printf("So hang khong hop le\n");
        return 0;
    } else if (cols <= 0) {
        printf("So cot khong hop le\n");
        return 0;
    }

    arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Khong the cap phat bo nho cho dong %d\n", i);
            return 1;
        }
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Nhap dong k can tinh tong (bat dau tu 0): ");
    scanf("%d", &k);

    if (k < 0 || k >= rows) {
        printf("Hang can tinh khong ton tai\n");
        for (int i = 0; i < rows; i++) {
            free(arr[i]);
        }
        free(arr);
        return 0;
    }

    int tong = tinhTongDongK(arr, k, cols);
    printf("sum = %d\n", tong);

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
