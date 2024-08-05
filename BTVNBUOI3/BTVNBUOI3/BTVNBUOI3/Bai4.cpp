#include <stdio.h>
#include <stdlib.h>

// H�m ho�n ??i hai s? nguy�n
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// H�m s?p x?p ???ng ch�o ph? t?ng d?n/gi?m d?n
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


int main() {
    int a[100][100], n;
    int choice, tangDan;

    printf("Nh?p c?p c?a ma tr?n vu�ng: ");
    scanf("%d", &n);

    printf("Nh?p c�c ph?n t? c?a ma tr?n:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    do {
        printf("\n=== MENU ===\n");
        printf("1. S?p x?p ???ng ch�o ph? t?ng d?n/gi?m d?n\n");
        printf("2. S?p x?p d�ng l? t?ng d?n, d�ng ch?n gi?m d?n\n");
        printf("3. S?p x?p c?t l? gi?m d?n, c?t ch?n t?ng d?n\n");
        printf("4. S?p x?p c�c ???ng ch�o ch�nh v� song song v?i n� t?ng d?n\n");
        printf("5. Di chuy?n c�c ph?n t? ch?n l�n tr�n, l? xu?ng d??i\n");
        printf("6. Ki?m tra ??i x?ng qua ???ng ch�o ch�nh\n");
        printf("0. Tho�t\n");
        printf("L?a ch?n c?a b?n: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Ch?n 1 ?? s?p x?p t?ng d?n, 0 ?? s?p x?p gi?m d?n: ");
            scanf("%d", &tangDan);
            sapXepDuongCheoPhu(a, n, tangDan);
            printf("Ma tr?n sau khi s?p x?p ???ng ch�o ph?:\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
            break;
        case 0:
            printf("Tho�t ch??ng tr�nh.\n");
            break;
        default:
            printf("L?a ch?n kh�ng h?p l?!\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
