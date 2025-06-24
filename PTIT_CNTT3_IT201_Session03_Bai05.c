#include <stdio.h>
#include <stdlib.h>

int tinhTongCheoChinh(int **arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i][i];
    }
    return tong;
}

int tinhTongCheoPhu(int **arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i][n - 1 - i];
    }
    return tong;
}

int main() {
    int rows, cols;
    int **arr;

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 && cols <= 0) {
        printf("So cot va so hang khong hop le\n");
        return 0;
    }
    if (rows <= 0) {
        printf("So hang khong hop le\n");
        return 0;
    }
    if (cols <= 0) {
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
            printf("Khong the cap phat dong %d\n", i);
            return 1;
        }
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    if (rows == cols) {
        int tongChinh = tinhTongCheoChinh(arr, rows);
        int tongPhu = tinhTongCheoPhu(arr, rows);
        printf("Tong duong cheo chinh = %d\n", tongChinh);
        printf("Tong duong cheo phu = %d\n", tongPhu);
    } else {
        printf("Khong ton tai duong cheo chinh\n");
        printf("Khong ton tai duong cheo phu\n");
    }

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
