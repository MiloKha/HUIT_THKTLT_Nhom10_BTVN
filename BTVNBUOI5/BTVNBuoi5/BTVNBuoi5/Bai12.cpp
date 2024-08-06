#include <stdio.h>

// Hàm tính x_n và y_n đệ quy
void calculate_sequences_recursive(int n, int* x, int* y) {
    if (n == 0) {
        *x = 1;
        *y = 0;
        return;
    }

    int x_prev, y_prev;
    calculate_sequences_recursive(n - 1, &x_prev, &y_prev);

    *x = x_prev + y_prev;
    *y = 3 * x_prev + 2 * y_prev;
}

int main() {
    int n;

    // Nhập giá trị n từ bàn phím
    printf("Nhap n: ");
    scanf("%d", &n);

    int x_n, y_n;
    calculate_sequences_recursive(n, &x_n, &y_n);

    printf("x_%d = %d\n", n, x_n);
    printf("y_%d = %d\n", n, y_n);

    return 0;
}
