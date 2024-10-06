class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        
        int m=t.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return helper(0,0,t,m,dp);
    }

    int helper(int i, int j, vector<vector<int>>& t, int m, vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1) return t[i][j];
        int down=helper(i+1, j, t, m, dp)+t[i][j];
        int right=helper(i+1, j+1, t, m, dp)+t[i][j];
        return dp[i][j]=min(down, right);

    }
};