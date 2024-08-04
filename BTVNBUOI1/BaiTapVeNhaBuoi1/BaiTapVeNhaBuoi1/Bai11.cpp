#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Hàm xuất các số cực tiểu trong mảng
void printLocalMinima(int arr[], int size) {
    if (size < 3) {
        printf("Mang phai co it nhat 3 phan tu.\n");
        return;
    }

    printf("Cac so cuc tieu trong mang: ");
    for (int i = 1; i < size - 1; i++) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
// Hàm xóa phần tử tại vị trí k
void deleteElement(int arr[], int* size, int k) {
    if (k < 0 || k >= *size) {
        printf("Vi tri xoa khong hop le.\n");
        return;
    }

    for (int i = k; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int arr[SIZE] = { 1, 2, 4, 3, 7, 8, 6, 9, 10, 5 };
    int size = 10;
    int choice, k, x;

    do {
        // Hiển thị menu
        printf("\nMenu:\n");
        printf("1. Xuat cac so cuc tieu\n");
        printf("2. Xoa phan tu tai vi tri k\n");
        printf("6. Thoat\n");
        printf("Chon tu 1 den 6: ");
        scanf("%d", &choice);

        // Xóa ký tự newline sau khi nhập số
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            printLocalMinima(arr, size);
            break;
        case 2:
            printf("Nhap vi tri k: ");
            scanf("%d", &k);
            deleteElement(arr, &size, k);
            printf("Mang sau khi xoa phan tu: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 6:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 6);

    return 0;
}
