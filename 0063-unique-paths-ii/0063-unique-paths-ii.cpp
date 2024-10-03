class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(m-1, n-1, grid, dp);
    }

int helper(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
    dp[0][0]=1;
   for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 && j==0) continue;
             if (grid[i][j] == 1) {
                dp[i][j] = 0;continue;}
             int up=0, left=0;
            if(i>0) up=dp[i-1][j];
            if(j>0) left=dp[i][j-1];
            dp[i][j]=up+left;
        }
    }
    return dp[m][n];
}

};