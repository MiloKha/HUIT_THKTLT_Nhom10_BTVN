#include <stdio.h>

int main() {
    int a, b, c;
    float result;

    // Nhập 3 số nguyên a, b, c
    printf("Nhập số nguyên a: ");
    scanf("%d", &a);
    printf("Nhập số nguyên b: ");
    scanf("%d", &b);
    printf("Nhập số nguyên c: ");
    scanf("%d", &c);

    // Kiểm tra nếu a-b bằng 0 để tránh chia cho 0
    if (a - b == 0) {
        printf("Lỗi: Phép tính không hợp lệ vì a - b = 0, không thể thực hiện phép chia.\n");
    }
    else {
        // Thực hiện phép chia c / (a - b)
        result = (float)c / (a - b);
        printf("Kết quả của c / (a - b) là: %.2f\n", result);
    }

    return 0;
}
