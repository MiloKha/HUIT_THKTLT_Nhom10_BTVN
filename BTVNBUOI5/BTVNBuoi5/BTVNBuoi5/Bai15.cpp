#include <stdio.h>

// Hàm tính tổng A_1 đến A_{n-1} bằng đệ quy
int sum_A_recursive(int n) {
    if (n == 1) {
        return 0; // Tổng từ A_1 đến A_{0} là 0
    }
    return A_recursive(n - 1) + sum_A_recursive(n - 1);
}

// Hàm tính giá trị A_n bằng đệ quy
int A_recursive(int n) {
    if (n == 1) {
        return 1;
    }
    int sum = sum_A_recursive(n);
    return n * sum;
}

int main() {
    int n;

    // Nhập giá trị n từ bàn phím
    printf("Nhap n: ");
    scanf("%d", &n);

    // Tính giá trị của A_n
    int result = A_recursive(n);
    printf("A(%d) = %d\n", n, result);

    return 0;
}
