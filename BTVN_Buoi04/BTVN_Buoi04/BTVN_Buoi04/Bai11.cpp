#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 100

int is_all_digits(const char* str) {
    while (*str) {
        if (!isdigit((unsigned char)*str)) {
            return 0; 
        }
        str++;
    }
    return 1; 
}

int main() {
    char strings[MAX_STRINGS][MAX_LENGTH];
    int n;

    printf("Nhap so luong chuoi: ");
    scanf_s("%d", &n);

    if (n < 1 || n > MAX_STRINGS) {
        printf("So luong chuoi khong hop le.\n");
        return 1;
    }

    while (getchar() != '\n');

    for (int i = 0; i < n; i++) {
        printf("Nhap chuoi %d (max %d ky tu): ", i + 1, MAX_LENGTH - 1);
        fgets(strings[i], sizeof(strings[i]), stdin);
        size_t len = strlen(strings[i]);
        if (len > 0 && strings[i][len - 1] == '\n') {
            strings[i][len - 1] = '\0';
        }
    }

    printf("Nhung chuoi chua toan ky tu so:\n");
    for (int i = 0; i < n; i++) {
        if (is_all_digits(strings[i])) {
            printf("%s\n", strings[i]);
        }
    }

    return 0;
}
