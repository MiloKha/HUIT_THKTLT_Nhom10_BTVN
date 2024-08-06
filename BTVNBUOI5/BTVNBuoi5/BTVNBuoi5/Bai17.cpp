#include <stdio.h>

// Hàm tính giá trị X_n bằng đệ quy
int X_recursive(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return X_recursive(n - 1) + (n - 1) * X_recursive(n - 2);
    }
}

int main() {
    int n;

    // Nhập giá trị n từ bàn phím
    printf("Nhap n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Gia tri n phai lon hon hoac bang 1.\n");
        return 1;
    }

    // Tính giá trị của X_n
    int result = X_recursive(n);
    printf("X(%d) = %d\n", n, result);

    return 0;
}
