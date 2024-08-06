#include <stdio.h>

// Hàm tính giá trị A_n bằng đệ quy
int A_recursive(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n % 2 == 0) {
        int half = n / 2;
        return half + A_recursive(half) + 2;
    }
    else {
        int half = (n - 1) / 2;
        return half * half + A_recursive(half) * A_recursive(half + 1) + 1;
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

    // Tính giá trị của A_n
    int result = A_recursive(n);
    printf("A(%d) = %d\n", n, result);

    return 0;
}
