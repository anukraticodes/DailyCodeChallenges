class Solution {
public:
    int minDistance(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(s, t, n - 1, m - 1, dp);
}

int helper(const string& s, const string& t, int i, int j, vector<vector<int>>& dp) {
   
    if (i < 0) return j + 1;  
    if (j < 0) return i + 1;  

   
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) {
        return dp[i][j] = helper(s, t, i - 1, j - 1, dp);
    }

    int substitute = helper(s, t, i - 1, j - 1, dp);  
    int deleteChar = helper(s, t, i - 1, j, dp);       
    int insertChar = helper(s, t, i, j - 1, dp);      

    return dp[i][j] = 1 + min({substitute, deleteChar, insertChar});
}
};