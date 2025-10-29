class Solution {
public:

    int maxCoins(vector<int>& nums) {
        vector<int> nnums;
        nnums.push_back(1);
        for(auto n:nums) nnums.push_back(n);
        nnums.push_back(1);
        int m=nnums.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for(int len=1; len<=m-2; len++){
            for (int i = 1; i + len - 1 <= m - 2; i++) {
            int j = i + len - 1; 
                int ans=0;
                for(int k=i; k<=j; k++){
                    int coins = nnums[i-1] * nnums[k] * nnums[j+1] 
                    + dp[i][k-1]+ dp[k+1][j];
                    ans=max(ans, coins);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][m-2];
    }
};