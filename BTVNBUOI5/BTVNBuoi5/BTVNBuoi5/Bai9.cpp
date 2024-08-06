#include <stdio.h>
#include <math.h>

// Hàm tính S1(n) theo cách đệ quy
double S1_recursive(int n, int k) {
    if (k > n) return 0;
    return 1.0 / (k * (k + 1) * (k + 2)) + S1_recursive(n, k + 1);
}

// Hàm tính S1(n) theo cách khử đệ quy
double S1_iterative(int n) {
    double sum = 0.0;
    for (int k = 1; k <= n; ++k) {
        sum += 1.0 / (k * (k + 1) * (k + 2));
    }
    return sum;
}
// Hàm tính S2(n) theo cách đệ quy
double S2_recursive(int n) {
    if (n == 1) return 1.0;
    return pow(n, 2) + S2_recursive(n - 1);
}

// Hàm tính S2(n) theo cách khử đệ quy
double S2_iterative(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += pow(i, 2);
    }
    return sum;
}


int main() {
    int choice, n;

    do {
        printf("Menu:\n");
        printf("1. Tinh S1(n) theo cach de quy\n");
        printf("2. Tinh S1(n) theo cach khu de quy\n");
        printf("3. Tinh S2(n) theo cach de quy\n");
        printf("4. Tinh S2(n) theo cach khu de quy\n");
        printf("9. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 8) {
            printf("Nhap gia tri n: ");
            scanf("%d", &n);
        }

        switch (choice) {
        case 1:
            printf("S1(%d) theo cach de quy = %.6f\n", n, S1_recursive(n, 1));
            break;
        case 2:
            printf("S1(%d) theo cach khu de quy = %.6f\n", n, S1_iterative(n));
            break;
        case 3:
            printf("S2(%d) theo cach de quy = %.6f\n", n, S2_recursive(n));
            break;
        case 4:
            printf("S2(%d) theo cach khu de quy = %.6f\n", n, S2_iterative(n));
            break;
        case 9:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }

    } while (choice != 9);

    return 0;
}
