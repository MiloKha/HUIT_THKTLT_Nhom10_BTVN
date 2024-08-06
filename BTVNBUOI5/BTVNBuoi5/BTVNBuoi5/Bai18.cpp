#include <stdio.h>
// Hàm tính giá trị x_n bằng đệ quy
int x_recursive(int n) {
    // Định nghĩa giá trị cơ bản
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return 2;
    }
    else {
        int sum = 0;
        // Tính tổng của các giá trị từ x_0 đến x_{n-1}
        for (int i = 0; i < n; i++) {
            sum += x_recursive(i);
        }
        return n * x_recursive(0) + (n - 1) * x_recursive(1) + sum;
    }
}

int main() {
    int n;

    // Nhập giá trị n từ bàn phím
    printf("Nhap n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Gia tri n phai lon hon hoac bang 0.\n");
        return 1;
    }
    // Tính giá trị của x_n
    int result = x_recursive(n);
    printf("x(%d) = %d\n", n, result);

    return 0;
}
