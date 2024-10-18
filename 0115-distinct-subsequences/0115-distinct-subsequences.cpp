class Solution {
public:

const int mod=1e9+7;
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        return helper(s, t, n, m, dp);
    }

    int helper(string& s,string& t, int n, int m,vector<vector<int>>& dp){
        for(int i=0; i<=n; i++){
            dp[i][0]=1;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    int nottake=dp[i-1][j-1];
                    int take=dp[i-1][j];
                    dp[i][j]=(take+nottake)%mod;
                }
                else dp[i][j]=dp[i-1][j];
            }
        }

        return dp[n][m];
    }
};