class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        for(int i=1; i<=n; i++){
            dp[i][0]=i;
        }
        for(int j=1; j<=m; j++){
            dp[0][j]=j;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[n][m];
    }

    // int helper(vector<vector<int>>& dp, string& w1, string& w2, int i, int j){
    //     if(i==0) return j;
    //     if(j==0) return i;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(w1[i-1]==w2[j-1]) return dp[i][j]=helper(dp, w1, w2, i-1, j-1);
    //     return dp[i][j]=1+min({helper(dp, w1, w2, i-1, j), helper(dp, w1, w2, i, j-1), helper(dp, w1, w2, i-1, j-1)});
    // }
};