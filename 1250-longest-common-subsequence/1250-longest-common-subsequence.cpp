class Solution {
public:
     int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size(), m = t2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Fill the dp table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (t1[i] == t2[j]) {
                    if (i > 0 && j > 0) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = 1;  // Handle the first row/column
                    }
                } else {
                    int top = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = max(top, left);
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};