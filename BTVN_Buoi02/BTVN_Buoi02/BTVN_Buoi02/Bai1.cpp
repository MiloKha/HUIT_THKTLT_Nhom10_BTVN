#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 100

bool la_nguyen_to(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void tao_mang_ngau_nhien(int a[], int* n) {
    do {
        printf("Nhap so phan tu (>= 15): ");
        scanf_s("%d", n);
    } while (*n < 15);

    for (int i = 0; i < *n; i++) {
        a[i] = rand() % MAX;  
    }

    printf("Mang ngau nhien da tao: ");
    for (int i = 0; i < *n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void liet_ke_nguyen_to(int a[], int n) {
    bool co_nguyen_to = false;
    for (int i = 0; i < n; i++) {
        if (la_nguyen_to(a[i])) {
            printf("%d ", a[i]);
            co_nguyen_to = true;
        }
    }
    if (!co_nguyen_to) printf("Khong co so nguyen to nao nho hon %d.\n", n);
}

int chu_so_dau_le(int n) {
    while (n >= 10) n /= 10;
    return n % 2 != 0;
}

int tong_chu_so_dau_le(int a[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (chu_so_dau_le(a[i])) tong += a[i];
    }
    return tong;
}

void dem_so_lan_xuat_hien(int a[], int n) {
    int dem[MAX] = { 0 };

    for (int i = 0; i < n; i++) {
        dem[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (dem[a[i]] != 0) {
            printf("%d xuat hien %d lan\n", a[i], dem[a[i]]);
            dem[a[i]] = 0;
        }
    }
}

void hien_thi_menu() {
    printf("Chon chuc nang:\n");
    printf("1. Tao mang ngau nhien\n");
    printf("2. Liet ke cac so nguyen to nho hon n\n");
    printf("3. Tinh tong cac phan tu co chu so dau la chu so le\n");
    printf("4. Liet ke so lan xuat hien cua cac phan tu trong mang\n");
    printf("5. Sap xep mang co so chan tang dan, so le giam dan\n");
    printf("6. Tim day con giam dai nhat\n");
    printf("7. Tim so nho thu 2 trong mang\n");
    printf("8. Tim phan tu co chua chu so x\n");
    printf("9. Sap xep chan tang le giu nguyen vi tri\n");
    printf("10. Sap xep le o dau chan o cuoi\n");
}

int main() {
    srand((unsigned int)time(NULL));
    int a[MAX], n;
    int chon;

    do {
        hien_thi_menu();
        printf("Lua chon: ");
        scanf_s("%d", &chon);

        switch (chon) {
        case 1:
            tao_mang_ngau_nhien(a, &n);
            break;
        case 2:
            printf("Nhap so nguyen n: ");
            scanf_s("%d", &n);
            liet_ke_nguyen_to(a, n);
            break;
        case 3:
            printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tong_chu_so_dau_le(a, n));
            break;
        case 4:
            dem_so_lan_xuat_hien(a, n);
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (chon >= 1 && chon <= 10);

    return 0;
}
