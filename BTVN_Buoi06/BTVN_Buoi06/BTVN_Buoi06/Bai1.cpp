#include <stdio.h>

// Hàm đệ quy di chuyển các đĩa từ chồng nguồn (src) sang chồng đích (dest) sử dụng chồng trung gian (aux)
void thap_hanoi(int n, char src, char dest, char aux) {
    if (n == 1) {
        // Nếu chỉ còn một đĩa, di chuyển từ chồng src sang chồng dest
        printf("Di chuyen dia 1 tu %c sang %c\n", src, dest);
        return;
    }

    // Bước 1: Di chuyển n-1 đĩa từ chồng src sang chồng aux, sử dụng chồng dest làm trung gian
    thap_hanoi(n - 1, src, aux, dest);

    // Bước 2: Di chuyển đĩa lớn nhất từ chồng src sang chồng dest
    printf("Di chuyen dia %d tu %c sang %c\n", n, src, dest);

    // Bước 3: Di chuyển n-1 đĩa từ chồng aux sang chồng dest, sử dụng chồng src làm trung gian
    thap_hanoi(n - 1, aux, dest, src);
}

int main() {
    int n;

    // Nhập số lượng đĩa
    printf("Nhap so luong dia: ");
    scanf_s("%d", &n);

    // Kiểm tra số lượng đĩa hợp lệ
    if (n <= 0) {
        printf("So luong dia phai lon hon 0.\n");
        return 1;
    }

    // Gọi hàm đệ quy để bắt đầu di chuyển các đĩa
    thap_hanoi(n, 'A', 'C', 'B');

    return 0;
}
