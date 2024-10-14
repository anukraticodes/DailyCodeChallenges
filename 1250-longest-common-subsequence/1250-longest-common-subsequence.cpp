class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size(), m = t2.size();
        // Create a (n+1) x (m+1) dp table initialized to 0
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (t1[i - 1] == t2[j - 1]) {
                    // If characters match, take the diagonal value + 1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // If not, take the maximum from top or left cell
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The answer is in the bottom-right corner of the dp table
        return dp[n][m];
    }
};