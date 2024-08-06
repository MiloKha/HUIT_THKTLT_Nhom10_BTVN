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
// Hàm tính S3(n) theo cách đệ quy
int S3_recursive(int n) {
    if (n == 1) return 1;
    return n * (n + 1) / 2 + S3_recursive(n - 1);
}

// Hàm tính S3(n) theo cách khử đệ quy
int S3_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i * (i + 1) / 2;
    }
    return sum;
}
// Hàm tính S4(n) theo cách đệ quy
double factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

double S4_recursive(int n, int k) {
    if (k > n) return 0;
    return ((k * (k + 1)) / factorial(2 * k)) * (pow(-1, k)) + S4_recursive(n, k + 1);
}

// Hàm tính S4(n) theo cách khử đệ quy
double S4_iterative(int n) {
    double sum = 0.0;
    for (int k = 1; k <= n; ++k) {
        sum += ((k * (k + 1)) / factorial(2 * k)) * (pow(-1, k));
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
        printf("5. Tinh S3(n) theo cach de quy\n");
        printf("6. Tinh S3(n) theo cach khu de quy\n");
        printf("7. Tinh S4(n) theo cach de quy\n");
        printf("8. Tinh S4(n) theo cach khu de quy\n");
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
        case 5:
            printf("S3(%d) theo cach de quy = %d\n", n, S3_recursive(n));
            break;
        case 6:
            printf("S3(%d) theo cach khu de quy = %d\n", n, S3_iterative(n));
            break;
        case 7:
            printf("S4(%d) theo cach de quy = %.6f\n", n, S4_recursive(n, 1));
            break;
        case 8:
            printf("S4(%d) theo cach khu de quy = %.6f\n", n, S4_iterative(n));
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
