class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        int n=m.size();
        if(m.size()==0) return -1;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int i=0; i<n; i++){
            helper(m,dp,0,i,n);
        }
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            ans=min(ans, dp[0][i]);
        }
        return ans;
    }


    void helper(vector<vector<int>>& m,vector<vector<int>>& dp, int i, int j, int n){
        for(int i=0; i<n; i++){
            dp[n-1][i]=m[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int down=j>=0&&j<=n-1?dp[i+1][j]:INT_MAX;
                int right=j+1>=0&&j+1<=n-1?dp[i+1][j+1]:INT_MAX;
                int left=j-1>=0&&j-1<=n-1?dp[i+1][j-1]:INT_MAX;
                dp[i][j]=min({down, left, right})+m[i][j];
            }
        }
    }
};