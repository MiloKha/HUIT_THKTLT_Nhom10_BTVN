#include <stdio.h>

// Hàm tính giá trị phần tử thứ n của cấp số nhân (sử dụng đệ quy)
unsigned long long geometric_sequence_recursive(int n, unsigned long long a, unsigned long long q) {
    if (n == 1) {
        return a;
    }
    else {
        return q * geometric_sequence_recursive(n - 1, a, q);
    }
}

int main() {
    int n;
    unsigned long long a, q;

    // Nhập giá trị a, q và n từ bàn phím
    printf("Nhap gia tri a (hang dau): ");
    scanf("%llu", &a);
    printf("Nhap gia tri q (cong boi): ");
    scanf("%llu", &q);
    printf("Nhap n (vi tri phan tu): ");
    scanf("%d", &n);

    // Tính giá trị phần tử thứ n của cấp số nhân
    unsigned long long result = geometric_sequence_recursive(n, a, q);
    printf("Gia tri phan tu thu %d cua cap so nhan la: %llu\n", n, result);

    return 0;
}
