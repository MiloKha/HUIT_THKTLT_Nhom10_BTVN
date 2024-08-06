#include <stdio.h>

// Hàm tính số Fibonacci thứ n (sử dụng đệ quy)
unsigned long long fibonacci(int n) {
    if (n <= 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Hàm xuất các số Fibonacci thuộc đoạn [m, n]
void printFibonacciInRange(int m, int n) {
    int i = 1;
    unsigned long long fib;

    // Tính và kiểm tra các số Fibonacci cho đến khi vượt quá n
    while (1) {
        fib = fibonacci(i);
        if (fib > n) break;
        if (fib >= m) printf("%llu ", fib);
        i++;
    }
    printf("\n");
}

int main() {
    int m, n;

    // Nhập giá trị m và n từ bàn phím
    printf("Nhap m: ");
    scanf("%d", &m);
    printf("Nhap n: ");
    scanf("%d", &n);

    // Xuất các số Fibonacci thuộc đoạn [m, n]
    printf("Cac so Fibonacci thuoc doan [%d, %d] la: ", m, n);
    printFibonacciInRange(m, n);

    return 0;
}
