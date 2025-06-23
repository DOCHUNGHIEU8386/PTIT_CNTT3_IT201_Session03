#include <stdio.h>

int tinhTongDongK(int arr[1000][1000], int k, int cols) {
    int tong = 0;
    for (int j = 0; j < cols; j++) {
        tong += arr[k][j];
    }
    return tong;
}

int main() {
    int rows, cols, k;
    int arr[1000][1000];

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
        return 0;
    }

    int tong = tinhTongDongK(arr, k, cols);
    printf("sum = %d\n", tong);

    return 0;
}
