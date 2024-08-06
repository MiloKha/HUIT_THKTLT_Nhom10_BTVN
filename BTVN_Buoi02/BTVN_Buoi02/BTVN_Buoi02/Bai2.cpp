#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int phan_nguyen;
    int tu_so;
    int mau_so;
} HonSo;

// Hàm tạo mảng hỗn số ngẫu nhiên
void tao_mang_hon_so_ngau_nhien(HonSo b[], int* n) {
    do {
        printf("Nhap so phan tu: ");
        scanf_s("%d", n);
    } while (*n <= 0);

    for (int i = 0; i < *n; i++) {
        b[i].phan_nguyen = rand() % 20 - 10; // Phần nguyên từ -10 đến 10
        b[i].tu_so = rand() % 20 - 10;       // Tử số từ -10 đến 10
        do {
            b[i].mau_so = rand() % 19 + 1;   // Mẫu số từ 1 đến 20
        } while (b[i].mau_so == 0);
    }

    printf("Mang hon so ngau nhien da tao:\n");
    for (int i = 0; i < *n; i++) {
        printf("%d %d/%d\n", b[i].phan_nguyen, b[i].tu_so, b[i].mau_so);
    }
    printf("\n");
}

// Hàm tìm hỗn số x bằng Linear Search
int linear_search(HonSo b[], int n, HonSo x) {
    for (int i = 0; i < n; i++) {
        if (b[i].phan_nguyen == x.phan_nguyen &&
            b[i].tu_so == x.tu_so &&
            b[i].mau_so == x.mau_so) {
            return i;
        }
    }
    return -1;
}

void sap_xep_chan_le(HonSo b[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (b[i].phan_nguyen % 2 == 0) {
            HonSo temp = b[j];
            b[j] = b[i];
            b[i] = temp;
            j++;
        }
    }
}

void hien_thi_menu() {
    printf("Chon chuc nang:\n");
    printf("1. Tao mang hon so ngau nhien\n");
    printf("2. Tim hon so x bang linear search\n");
    printf("3. Sap xep chan len dau, le len cuoi\n");
    printf("4. Tim hon so x bang binary search (da sap xep)\n");
    printf("5. Chia mang thanh s1 va s2\n");
    printf("6. Xoa phan tu thu k\n");
    printf("7. Them hon so x vao vi tri k\n");
    printf("8. Tao mang phan so tu mang hon so\n");
    printf("9. Tinh tong cac phan tu cua mang\n");
    printf("10. Tim phan tu lon nhat/nho nhat\n");
    printf("11. Xuat vi tri cac phan tu co phan nguyen chan\n");
    printf("12. Xuat vi tri phan tu lon nhat/nho nhat\n");
}

int main() {
    srand((unsigned int)time(NULL));
    HonSo b[100];
    int s1[100];
    float s2[100];
    float c[100];
    int n;
    int chon;
    HonSo x;
    int k;

    do {
        hien_thi_menu();
        printf("Lua chon: ");
        scanf_s("%d", &chon);

        switch (chon) {
        case 1:
            tao_mang_hon_so_ngau_nhien(b, &n);
            break;
        case 2:
            printf("Nhap hon so can tim (phan nguyen, tu so, mau so): ");
            scanf_s("%d %d %d", &x.phan_nguyen, &x.tu_so, &x.mau_so);
            k = linear_search(b, n, x);
            if (k != -1) printf("Tim thay hon so tai vi tri %d\n", k);
            else printf("Khong tim thay hon so\n");
            break;
        case 3:
            sap_xep_chan_le(b, n);
            printf("Mang sau khi sap xep:\n");
            for (int i = 0; i < n; i++) {
                printf("%d %d/%d\n", b[i].phan_nguyen, b[i].tu_so, b[i].mau_so);
            }
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
        printf("\n");
    } while (chon != 0);

    return 0;
}
