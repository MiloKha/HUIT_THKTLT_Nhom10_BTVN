#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
    if (a < b) return (a < c) ? a : c;
    return (b < c) ? b : c;
}

int levenshtein_distance(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int** dp = (int**)malloc((len1 + 1) * sizeof(int*));

    for (int i = 0; i <= len1; i++) {
        dp[i] = (int*)malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++) dp[i][0] = i;
    for (int j = 0; j <= len2; j++) dp[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dp[i][j] = min(dp[i - 1][j] + 1,
                dp[i][j - 1] + 1,
                dp[i - 1][j - 1] + cost);
        }
    }

    int result = dp[len1][len2];

    for (int i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    char s1[MAX_LENGTH], s2[MAX_LENGTH];

    printf("Nhap chuoi s1 (max %d ky tu): ", MAX_LENGTH - 1);
    fgets(s1, sizeof(s1), stdin);
    size_t len = strlen(s1);
    if (len > 0 && s1[len - 1] == '\n') {
        s1[len - 1] = '\0';
    }

    printf("Nhap chuoi s2 (max %d ky tu): ", MAX_LENGTH - 1);
    fgets(s2, sizeof(s2), stdin);
    len = strlen(s2);
    if (len > 0 && s2[len - 1] == '\n') {
        s2[len - 1] = '\0';
    }

    int distance = levenshtein_distance(s1, s2);
    printf("So phep bien doi can thiet: %d\n", distance);

    return 0;
}
