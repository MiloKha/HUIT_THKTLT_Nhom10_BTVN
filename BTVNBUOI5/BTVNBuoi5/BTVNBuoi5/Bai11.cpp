#include <stdio.h>

// Hàm tính số Fibonacci thứ n (sử dụng đệ quy)
unsigned long long fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Hàm tìm số Fibonacci lớn nhất nhỏ hơn n (sử dụng đệ quy)
unsigned long long largest_fibonacci_less_than_n_recursive(int n, int index) {
    unsigned long long fib = fibonacci_recursive(index);
    if (fib >= n) {
        if (index == 1) return 0; // Trường hợp không có số Fibonacci nào nhỏ hơn n
        return fibonacci_recursive(index - 1);
    }
    return largest_fibonacci_less_than_n_recursive(n, index + 1);
}

// Hàm tìm số Fibonacci lớn nhất nhỏ hơn n (khử đệ quy)
unsigned long long largest_fibonacci_less_than_n_iterative(int n) {
    unsigned long long a = 0, b = 1;
    unsigned long long fib = 0;

    while (b < n) {
        fib = b;
        unsigned long long temp = a;
        a = b;
        b = temp + b;
    }

    return fib;
}

int main() {
    int choice, n;

    do {
        printf("Menu:\n");
        printf("1. Tim so Fibonacci lon nhat nho hon n (de quy)\n");
        printf("2. Tim so Fibonacci lon nhat nho hon n (khu de quy)\n");
        printf("3. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("Nhap n: ");
            scanf("%d", &n);
        }

        switch (choice) {
        case 1:
            printf("So Fibonacci lon nhat nho hon %d (de quy) la: %llu\n", n, largest_fibonacci_less_than_n_recursive(n, 1));
            break;
        case 2:
            printf("So Fibonacci lon nhat nho hon %d (khu de quy) la: %llu\n", n, largest_fibonacci_less_than_n_iterative(n));
            break;
        case 3:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }

    } while (choice != 3);

    return 0;
}
