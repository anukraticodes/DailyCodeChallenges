class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1, n-1, dp);
    }

int helper(int i, int j, vector<vector<int>>& dp){
   
    dp[0][0]=1;
    for(int row=0; row<=i; row++){
        for(int col=0; col<=j; col++){
            if(col==0&& row==0) continue;
            int up=0, left=0;
            if(row>0) up=dp[row-1][col];
            if(col>0) left=dp[row][col-1];
            dp[row][col]=up+left;
        }
    }
    return dp[i][j];
}

};