#include <stdio.h>

// Hàm tính U(n) đệ quy
int U_recursive(int n) {
    if (n < 6) {
        return n;
    }
    else {
        return U_recursive(n - 5) + U_recursive(n - 4) + U_recursive(n - 3) + U_recursive(n - 2) + U_recursive(n - 1);
    }
}

int main() {
    int n;

    // Nhập giá trị n từ bàn phím
    printf("Nhap n: ");
    scanf("%d", &n);

    // Tính giá trị của U(n)
    int result = U_recursive(n);
    printf("U(%d) = %d\n", n, result);

    return 0;
}
