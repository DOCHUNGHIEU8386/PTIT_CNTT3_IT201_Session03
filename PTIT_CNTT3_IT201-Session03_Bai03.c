#include <stdio.h>
#include <stdlib.h>

void importArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}

float calculateEvenAverage(int *array, int n) {
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            sum += array[i];
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    return (float)sum / count;
}

int main() {
    int n;
    int *array;

    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    importArray(array, n);

    float avg = calculateEvenAverage(array, n);

    printf("Trung binh cong cac so chan trong mang: %.2f\n", avg);

    free(array);

    return 0;
}
