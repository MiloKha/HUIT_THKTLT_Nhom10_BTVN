#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

void xoa_ky_tu(char* chuoi, char ky_tu_xoa) {
    char* src = chuoi; 
    char* dst = chuoi; 

    while (*src != '\0') {
        if (*src != ky_tu_xoa) {
            *dst = *src; 
            dst++; 
        }
        src++; 
    }
    *dst = '\0'; 
}

int main() {
    char chuoi[MAX_SIZE];
    char ky_tu_xoa;

    printf("Nhap chuoi (max %d ky tu): ", MAX_SIZE - 1);
    fgets(chuoi, sizeof(chuoi), stdin);
    size_t len = strlen(chuoi);
    if (len > 0 && chuoi[len - 1] == '\n') {
        chuoi[len - 1] = '\0';
    }

    printf("Nhap ky tu can xoa: ");
    scanf_s(" %c", &ky_tu_xoa);  

    xoa_ky_tu(chuoi, ky_tu_xoa);

    printf("Chuoi sau khi xoa ky tu '%c' la: %s\n", ky_tu_xoa, chuoi);

    return 0;
}
