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

void sap_xep_chan_tang_le_giam(int a[], int n) {
    int temp;
    // Sắp xếp chẵn tăng
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] % 2 == 0 && a[j] % 2 == 0 && a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    // Sắp xếp lẻ giảm
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] % 2 != 0 && a[j] % 2 != 0 && a[i] < a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int do_dai_day_con_giam_dai_nhat(int a[], int n) {
    int max_len = 1, len = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            len++;
        }
        else {
            if (len > max_len) max_len = len;
            len = 1;
        }
    }
    if (len > max_len) max_len = len;
    return max_len;
}

int tim_so_nho_thu_hai(int a[], int n) {
    int min = a[0], min2 = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min2 = min;
            min = a[i];
        }
        else if ((a[i] < min2 || min2 == -1) && a[i] != min) {
            min2 = a[i];
        }
    }
    return min2;
}

bool co_chua_chu_so(int so, int x) {
    char s[12], sx[3];
    sprintf_s(s, "%d", so);
    sprintf_s(sx, "%d", x);

    for (int i = 0; i < (int)strlen(s); i++) {
        for (int j = 0; j < (int)strlen(sx); j++) {
            if (s[i] == sx[j]) return true;
        }
    }
    return false;
}

void tim_phan_tu_chua_chu_so_x(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (co_chua_chu_so(a[i], x)) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

void sap_xep_chan_tang_le_nguyen(int a[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] % 2 == 0) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] % 2 == 0 && a[i] > a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
}

void sap_xep_le_chan(int a[], int n) {
    int temp;
    int i = 0, j = n - 1;
    while (i < j) {
        while (a[i] % 2 != 0 && i < j) i++;
        while (a[j] % 2 == 0 && i < j) j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
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
        case 5:
            sap_xep_chan_tang_le_giam(a, n);
            printf("Mang sau khi sap xep: ");
            for (int i = 0; i < n; i++) printf("%d ", a[i]);
            printf("\n");
            break;
        case 6:
            printf("Do dai day con giam dai nhat: %d\n", do_dai_day_con_giam_dai_nhat(a, n));
            break;
        case 7:
            printf("So nho thu hai trong mang: %d\n", tim_so_nho_thu_hai(a, n));
            break;
        case 8:
            int x;
            printf("Nhap x: ");
            scanf_s("%d", &x);
            printf("Cac phan tu trong mang co chua chu so %d: ", x);
            tim_phan_tu_chua_chu_so_x(a, n, x);
            break;
        case 9:
            sap_xep_chan_tang_le_nguyen(a, n);
            printf("Mang sau khi sap xep: ");
            for (int i = 0; i < n; i++) printf("%d ", a[i]);
            printf("\n");
            break;
        case 10:
            sap_xep_le_chan(a, n);
            printf("Mang sau khi sap xep: ");
            for (int i = 0; i < n; i++) printf("%d ", a[i]);
            printf("\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (chon >= 1 && chon <= 10);

    return 0;
}
