#include <stdio.h>
#include <stdlib.h>

void importArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

int findMaxNumber(int *array, int n) {
    int maxNumber = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maxNumber) {
            maxNumber = array[i];
        }
    }
    return maxNumber;
}

int main() {
    int n;
    int *array;

    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("Gia tri n khong hop le. n phai > 0 va < 1000.\n");
        return 1;
    }

    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }

    importArray(array, n);

    int maxValue = findMaxNumber(array, n);

    printf("Phan tu lon nhat trong mang la: %d\n", maxValue);

    free(array);
    return 0;
}
