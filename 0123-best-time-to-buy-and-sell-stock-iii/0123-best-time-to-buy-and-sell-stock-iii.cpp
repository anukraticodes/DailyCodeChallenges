class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        long profit=0;
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                   if(buy==0){
                    profit=max(dp[i+1][0][cap], -p[i]+dp[i+1][1][cap]);
                   }
                   else{
                    profit=max(dp[i+1][1][cap], p[i]+dp[i+1][0][cap-1]);
                   }
                   dp[i][buy][cap]=profit;
                }
            }
        }
        return dp[0][0][2];

    }
};