class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n=p.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        int profit=0;
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
               if(buy==0){
                profit=max(dp[i+1][0], -p[i]+dp[i+1][1]);
               }
               else{
                profit=max(dp[i+1][1], p[i]-fee+dp[i+1][0]);
               }
               dp[i][buy]=profit;
            }
        }
        return dp[0][0];
    }
};