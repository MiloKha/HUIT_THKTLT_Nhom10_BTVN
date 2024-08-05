#include <stdio.h>
#include <stdlib.h>

// Hàm hoán đổi hai số nguyên
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Hàm sắp xếp đường chéo phụ tăng dần/giảm dần
void sapXepDuongCheoPhu(int a[][100], int n, int tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && a[i][n - i - 1] > a[j][n - j - 1]) ||
                (!tangDan && a[i][n - i - 1] < a[j][n - j - 1])) {
                swap(&a[i][n - i - 1], &a[j][n - j - 1]);
            }
        }
    }
}

// Hàm sắp xếp dòng lẻ tăng dần, dòng chẵn giảm dần
void sapXepDong(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((i % 2 == 0 && a[i][j] > a[i][k]) || (i % 2 != 0 && a[i][j] < a[i][k])) {
                    swap(&a[i][j], &a[i][k]);
                }
            }
        }
    }
}
// Hàm sắp xếp cột lẻ giảm dần, cột chẵn tăng dần
void sapXepCot(int a[][100], int n) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int k = i + 1; k < n; k++) {
                if ((j % 2 == 0 && a[i][j] > a[k][j]) || (j % 2 != 0 && a[i][j] < a[k][j])) {
                    swap(&a[i][j], &a[k][j]);
                }
            }
        }
    }
}
// Hàm sắp xếp các phần tử trên các đường chéo chính và song song với nó tăng dần
void sapXepCheoChinhVaSongSong(int a[][100], int n) {
    for (int d = -n + 1; d < n; d++) {  // d là độ lệch so với đường chéo chính
        for (int i = 0; i < n; i++) {
            int j = i + d;
            if (j >= 0 && j < n) {
                for (int k = i + 1; k < n; k++) {
                    int l = k + d;
                    if (l >= 0 && l < n && a[i][j] > a[k][l]) {
                        swap(&a[i][j], &a[k][l]);
                    }
                }
            }
        }
    }
}
// Hàm di chuyển các phần tử sao cho chẵn ở trên, lẻ ở dưới
void diChuyenChanLe(int a[][100], int n) {
    int b[100][100], k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                b[k / n][k % n] = a[i][j];
                k++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                b[k / n][k % n] = a[i][j];
                k++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = b[i][j];
        }
    }
}
// Hàm kiểm tra đối xứng qua đường chéo chính
int kiemTraDoiXung(int a[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i][j] != a[j][i]) {
                return 0; // Không đối xứng
            }
        }
    }
    return 1; // Đối xứng
}
int main() {
    int a[100][100], n;
    int choice, tangDan;

    printf("Nhập cấp của ma trận vuông: ");
    scanf("%d", &n);

    printf("Nhập các phần tử của ma trận:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    do {
        printf("\n=== MENU ===\n");
        printf("1. Sắp xếp đường chéo phụ tăng dần/giảm dần\n");
        printf("2. Sắp xếp dòng lẻ tăng dần, dòng chẵn giảm dần\n");
        printf("3. Sắp xếp cột lẻ giảm dần, cột chẵn tăng dần\n");
        printf("4. Sắp xếp các đường chéo chính và song song với nó tăng dần\n");
        printf("5. Di chuyển các phần tử chẵn lên trên,lẻ xuống dưới\n");
        printf("6. Kiểm tra đối xứng qua đường chéo chính\n");
        printf("0. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Chọn 1 để sắp xếp tăng dần, 0 để sắp xếp giảm dần: ");
            scanf("%d", &tangDan);
            sapXepDuongCheoPhu(a, n, tangDan);
            printf("Ma trận sau khi sắp xếp đường chéo phụ:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            sapXepDong(a, n);
            printf("Ma trận sau khi sắp xếp theo dòng:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
            break;
        case 3:
            sapXepCot(a, n);
            printf("Ma trận sau khi sắp xếp theo cột:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
            break;
        case 4:
            sapXepCheoChinhVaSongSong(a, n);
            printf("Ma trận sau khi sắp xếp các đường chéo:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
            break;
        case 5:
            diChuyenChanLe(a, n);
            printf("Ma trận sau khi di chuyển chẵn lên trên, lẻ xuống dưới:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
            break;
        case 6:
            if (kiemTraDoiXung(a, n)) {
                printf("Ma trận đối xứng qua đường chéo chính.\n");
            }
            else {
                printf("Ma trận không đối xứng qua đường chéo chính.\n");
            }
            break;
     
        case 0:
            printf("Thoát chương trình.\n");
            break;
        default:
            printf("Lựa chọn không hợp lệ!\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
