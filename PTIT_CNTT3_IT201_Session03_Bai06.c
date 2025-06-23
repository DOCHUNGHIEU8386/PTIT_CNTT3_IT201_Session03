#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int *arr;

    printf("Nhap so luong phan tu ban dau (n): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap so luong phan tu muon them (m): ");
    scanf("%d", &m);

    if (m > 0) {
        int *temp = (int *)realloc(arr, (n + m) * sizeof(int));
        if (temp == NULL) {
            printf("Khong du bo nho khi them phan tu!\n");
            free(arr);
            return 1;
        }
        arr = temp;

        printf("Nhap %d phan tu them:\n", m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &arr[n + i]);
        }

        n = n + m;
    }

    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" ]\n");

    free(arr);

    return 0;
}
