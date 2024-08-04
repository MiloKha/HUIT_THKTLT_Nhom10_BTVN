#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void inputArray(int arr[], int* size) {
    printf("Nhap so phan tu: ");
    scanf("%d", size);

    if (*size > MAX_SIZE) {
        printf("So luong phan tu vuot qua gioi han, lay gia tri toi da la %d.\n", MAX_SIZE);
        *size = MAX_SIZE;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < *size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(const int arr[], int size) {
    printf("Mang:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void performDivision(const int a[], int sizeA, const int b[], int sizeB) {
    printf("Ket qua phep chia:\n");

    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (b[j] != 0) {
                printf("%d / %d = %.2f\n", a[i], b[j], (float)a[i] / b[j]);
            }
            else {
                printf("Khong the chia cho 0: %d / %d\n", a[i], b[j]);
            }
        }
    }
}

int main() {
    int a[MAX_SIZE], b[MAX_SIZE];
    int sizeA, sizeB;
    int choice;

    do {
        // Hiển thị menu
        printf("\nMenu:\n");
        printf("1. Nhap mang a\n");
        printf("2. Nhap mang b\n");
        printf("3. Tinh va xuat ket qua phep chia\n");
        printf("4. Thoat\n");
        printf("Chon tu 1 den 4: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            inputArray(a, &sizeA);
            break;
        case 2:
            inputArray(b, &sizeB);
            break;
        case 3:
            if (sizeA > 0 && sizeB > 0) {
                printArray(a, sizeA);
                printArray(b, sizeB);
                performDivision(a, sizeA, b, sizeB);
            }
            else {
                printf("Ban can nhap du hai mang truoc khi tinh toan.\n");
            }
            break;
        case 4:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
