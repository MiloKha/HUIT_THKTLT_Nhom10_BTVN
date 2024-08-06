#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool la_chuoi_doi_xung(const char* str) {
    int len = (int)strlen(str);  
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[100];

    printf("Nhap chuoi: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }

        if (la_chuoi_doi_xung(str)) {
            printf("Chuoi '%s' la doi xung.\n", str);
        }
        else {
            printf("Chuoi '%s' khong la doi xung.\n", str);
        }
    }
    else {
        printf("Loi khi nhap chuoi.\n");
    }

    return 0;
}
