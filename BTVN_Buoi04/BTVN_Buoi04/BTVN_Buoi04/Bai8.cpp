#include <stdio.h>
#include <string.h>

int main() {
    char s1[200], s2[100];
    char* ptr;
    int vi_tri;

    printf("Nhap chuoi s1: ");
    fgets(s1, sizeof(s1), stdin);
    size_t len1 = strlen(s1);
    if (len1 > 0 && s1[len1 - 1] == '\n') {
        s1[len1 - 1] = '\0';
    }

    printf("Nhap chuoi s2: ");
    fgets(s2, sizeof(s2), stdin);
    size_t len2 = strlen(s2);
    if (len2 > 0 && s2[len2 - 1] == '\n') {
        s2[len2 - 1] = '\0';
    }

    ptr = strstr(s1, s2);
    if (ptr != NULL) {
        vi_tri = (int)(ptr - s1);  
        printf("Chuoi s2 xuat hien trong s1 tai vi tri %d.\n", vi_tri);
    }
    else {
        strcat_s(s1, sizeof(s1), s2);  
        printf("Chuoi s2 khong co trong s1. Sau khi noi, chuoi s1 la: %s\n", s1);
    }

    return 0;
}
