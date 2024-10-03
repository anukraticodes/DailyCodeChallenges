class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        if(grid.empty()||grid[0].empty()) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(grid, m-1, n-1, dp);
    }

int helper(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){
if(m<0||n<0) return INT_MAX;
if(m==0&&n==0) return grid[0][0];
if(dp[m][n]!=-1) return dp[m][n];
int up=helper(grid,m-1,n,dp);
int left=helper(grid,m,n-1,dp);
return dp[m][n]=min(up,left)+grid[m][n];
// if(dp[m][n]!=-1) return dp[m][n];
// dp[0][0]=grid[0][0];
// for(int i=1;i<m;i++){
//     dp[0][i]=dp[0][i-1]+grid[0][i];
// }
// for(int i=1;i<n;i++){
//     dp[i][0]=dp[i-1][0]+grid[i][0];
// }
// for(int i=0; i<=m; i++){
//     for(int j=0; j<=n; j++){
// if(i==0&&j==0) continue;
// int up=dp[i-1][j];
// int left=dp[i][j-1];
// dp[i][j]=min(up,left)+grid[i][j];
//     }
   
// }
// return dp[m][n];
}

};