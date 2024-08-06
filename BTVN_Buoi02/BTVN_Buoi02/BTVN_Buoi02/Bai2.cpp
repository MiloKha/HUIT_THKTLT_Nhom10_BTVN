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

int so_sanh_hon_so(HonSo x, HonSo y) {
    float fx = x.phan_nguyen + (float)x.tu_so / x.mau_so;
    float fy = y.phan_nguyen + (float)y.tu_so / y.mau_so;
    if (fx < fy) return -1;
    if (fx > fy) return 1;
    return 0;
}

void sap_xep_phan_so(HonSo b[], int n, bool tang) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int cmp = so_sanh_hon_so(b[i], b[j]);
            if ((tang && cmp > 0) || (!tang && cmp < 0)) {
                HonSo temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}

int binary_search(HonSo b[], int n, HonSo x, bool tang) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = so_sanh_hon_so(b[mid], x);
        if (cmp == 0) return mid;
        if ((tang && cmp < 0) || (!tang && cmp > 0)) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void chia_mang(HonSo b[], int n, int s1[], float s2[]) {
    for (int i = 0; i < n; i++) {
        s1[i] = b[i].phan_nguyen;
        s2[i] = (float)b[i].tu_so / b[i].mau_so;
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
        case 4:
            printf("Nhap hon so can tim (phan nguyen, tu so, mau so): ");
            scanf_s("%d %d %d", &x.phan_nguyen, &x.tu_so, &x.mau_so);
            sap_xep_phan_so(b, n, true); 
            k = binary_search(b, n, x, true);
            if (k != -1) printf("Tim thay hon so tai vi tri %d\n", k);
            else printf("Khong tim thay hon so\n");
            break;
        case 5:
            chia_mang(b, n, s1, s2);
            printf("Mang s1 (phan nguyen):\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", s1[i]);
            }
            printf("\nMang s2 (phan so):\n");
            for (int i = 0; i < n; i++) {
                printf("%.2f ", s2[i]);
            }
            printf("\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
        printf("\n");

    } while (chon != 0);

    return 0;
}
