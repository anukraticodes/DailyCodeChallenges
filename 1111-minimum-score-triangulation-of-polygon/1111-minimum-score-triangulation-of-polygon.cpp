class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int n=v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int gap=2; gap<n; gap++){
            for(int i=0; i+gap<n; i++){
                int j=i+gap;
                int ans=INT_MAX;
                for(int k=i+1; k<j; k++){
                    ans=min(ans, v[i]*v[j]*v[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][n-1];
    }
};