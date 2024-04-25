#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int longestIdealString(char* s, int k) {
    int n = strlen(s);
    int dp[n][27];
    memset(dp, -1, sizeof(dp));

    int rec(int i, int last) {
        if (i == n) {
            return 0;
        }
        if (dp[i][last] != -1) {
            return dp[i][last];
        }
        int ans = 0;
        if (last == 26 || abs(s[i] - 'a' - last) <= k) {
            ans = rec(i + 1, s[i] - 'a') + 1;
        }
        ans = fmax(ans, rec(i + 1, last));
        dp[i][last] = ans;
        return ans;
    }

    return rec(0, 26);
}

