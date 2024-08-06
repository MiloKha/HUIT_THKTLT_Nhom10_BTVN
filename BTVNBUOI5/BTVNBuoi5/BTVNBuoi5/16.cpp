#include <stdio.h>

#define MAX_N 1000 // Giới hạn kích thước mảng (có thể điều chỉnh nếu cần)

// Hàm tính giá trị Y_n bằng đệ quy trực tiếp
int Y_recursive(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else if (n == 3) {
        return 3;
    }
    else {
        return Y_recursive(n - 1) + 2 * Y_recursive(n - 2) + 3 * Y_recursive(n - 3);
    }
}

// Hàm tính giá trị Y_n bằng đệ quy với lưu trữ kết quả
int Y_recursive_memo(int n, int memo[]) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else if (n == 3) {
        return 3;
    }
    else if (memo[n] != -1) {
        return memo[n];
    }
    else {
        memo[n] = Y_recursive_memo(n - 1, memo) + 2 * Y_recursive_memo(n - 2, memo) + 3 * Y_recursive_memo(n - 3, memo);
        return memo[n];
    }
}

int main() {
    int n;
    int choice;

    // Nhập giá trị n từ bàn phím
    printf("Nhap n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Gia tri n phai lon hon 0.\n");
        return 1;
    }

    // Hiển thị menu cho người dùng
    printf("Chon phuong phap tinh Y_n:\n");
    printf("1. Dung de quy truc tiep\n");
    printf("2. Dung de quy voi luu tru ket qua\n");
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        // Tính giá trị của Y_n bằng đệ quy trực tiếp
        printf("Y(%d) = %d\n", n, Y_recursive(n));
        break;
    case 2:
        // Tính giá trị của Y_n bằng đệ quy với lưu trữ kết quả
        if (n >= MAX_N) {
            printf("n vuot qua gioi han cho phep.\n");
            return 1;
        }
        // Khởi tạo mảng memo để lưu trữ các giá trị đã tính toán
        int memo[MAX_N];
        for (int i = 1; i < MAX_N; ++i) {
            memo[i] = -1; // Khởi tạo mảng với giá trị chưa tính toán
        }
        printf("Y(%d) = %d\n", n, Y_recursive_memo(n, memo));
        break;
    default:
        printf("Lua chon khong hop le.\n");
        return 1;
    }

    return 0;
}

