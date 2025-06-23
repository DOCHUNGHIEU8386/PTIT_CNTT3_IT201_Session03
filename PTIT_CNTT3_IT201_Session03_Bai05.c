#include <stdio.h>

int tinhTongCheoChinh(int arr[1000][1000], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i][i];
    }
    return tong;
}

int tinhTongCheoPhu(int arr[1000][1000], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i][n - 1 - i];
    }
    return tong;
}

int main() {
    int rows, cols;
    int arr[1000][1000];

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

    return 0;
}
