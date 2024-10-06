class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        if(grid.empty()||grid[0].empty()) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(grid, m-1, n-1, dp);
    }

int helper(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){
dp[0][0]=grid[0][0];
for(int i=1; i<=m; i++){
    dp[i][0]=dp[i-1][0]+grid[i][0];
}
for(int j=1; j<=n; j++){
    dp[0][j]=dp[0][j-1]+grid[0][j];
}
for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
        int up=dp[i-1][j];
        int left=dp[i][j-1];
        dp[i][j]=min(up, left)+grid[i][j];
    }
}
return dp[m][n];
}

};