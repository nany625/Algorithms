#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN3(a, b, c) MIN(MIN(a, b), c)

int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int dp[len2 + 1];

    // 初始化 base case：dp[0][j] = j
    for (int j = 0; j <= len2; j++) {
        dp[j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        int prev = dp[0];  // `dp[i-1][0]`
        dp[0] = i;  // `dp[i][0]` = i
        
        for (int j = 1; j <= len2; j++) {
            int temp = dp[j];  // 保存 `dp[i-1][j]`
            
            if (s1[i - 1] == s2[j - 1]) {
                dp[j] = prev;  // 若字元相同，取 `dp[i-1][j-1]`
            } else {
                dp[j] = 1 + MIN3(dp[j],      // 刪除 s1[i-1]
                                  dp[j - 1],  // 插入 s2[j-1]
                                  prev);      // 替換 s1[i-1] -> s2[j-1]
            }
            
            prev = temp;  // 更新 `prev` 為 `dp[i-1][j]`
        }
    }

    return dp[len2];
}

int main() {
    char s1[] = "kitten";
    char s2[] = "sitting";
    printf("Levenshtein Distance: %d\n", levenshtein_distance(s1, s2));
    return 0;
}
