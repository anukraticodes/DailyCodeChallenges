class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int m=t.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return helper(0,0,t,m,dp);
    }

    int helper(int i, int j, vector<vector<int>>& t, int m, vector<vector<int>>& dp){
        for(int i=0; i<m; i++){
            dp[m-1][i]=t[m-1][i];
        }
        for(int i=m-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int down=dp[i+1][j];
                int dia=dp[i+1][j+1];
                dp[i][j]=min(down, dia)+t[i][j];
            }
        }
        return dp[0][0];
    }
};