#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

void chen_chuoi(char* str, const char* strInsert, int vt) {
    int lenStr = strlen(str);
    int lenInsert = strlen(strInsert);

    if (vt < 0 || vt > lenStr) {
        printf("Vi tri chen khong hop le.\n");
        return;
    }

    if (lenStr + lenInsert >= MAX_SIZE) {
        printf("Khong du bo nho de chen chuoi.\n");
        return;
    }

    memmove(str + vt + lenInsert, str + vt, lenStr - vt + 1);

    memcpy(str + vt, strInsert, lenInsert);
}

int main() {
    char str[MAX_SIZE];
    char strInsert[MAX_SIZE];
    int vt;

    printf("Nhap chuoi goc (max %d ky tu): ", MAX_SIZE - 1);
    if (fgets(str, sizeof(str), stdin) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }
    }

    printf("Nhap chuoi can chen (max %d ky tu): ", MAX_SIZE - 1);
    if (fgets(strInsert, sizeof(strInsert), stdin) != NULL) {
        size_t len = strlen(strInsert);
        if (len > 0 && strInsert[len - 1] == '\n') {
            strInsert[len - 1] = '\0';
        }
    }

    printf("Nhap vi tri can chen: ");
    int result = scanf_s("%d", &vt);  
    if (result != 1) {
        printf("Loi khi nhap vi tri.\n");
        return 1;  
    }

    chen_chuoi(str, strInsert, vt);

    printf("Chuoi sau khi chen la: %s\n", str);

    return 0;
}
