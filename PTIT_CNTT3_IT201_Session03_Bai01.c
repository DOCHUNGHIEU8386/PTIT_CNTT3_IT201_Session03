#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *array;

    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le. (0 < n < 1000)\n");
        return 1;
    }

    array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    printf("Nhap cac gia tri cua phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nCac phan tu vua nhap la:\n");
    for (int i = 0; i < n; i++) {
        printf("So thu %d = %d\n", i + 1, array[i]);
    }

    free(array);
    return 0;
}
