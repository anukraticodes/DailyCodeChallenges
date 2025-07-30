class Solution {
public:

     int helper(bool buy, int ind, vector<int>& p, vector<vector<int>>& dp){
        if(ind==p.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int op1, op2;
        long profit=0;
        if(buy==0){
            op1= helper(0, ind+1, p, dp);
            op2= -p[ind]+ helper(1, ind+1, p, dp);
            profit= max(op1, op2);
        }
        else{
           op1=helper(1, ind+1, p, dp);
            op2= p[ind]+ helper(0, ind+1, p, dp);
            profit= max(op1, op2);
        }
        return dp[ind][buy]=profit;
     }

    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        dp[n][0]=0, dp[n][1]=0;
        long profit=0;
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                if(buy==0){
                    profit=max(dp[i+1][buy], -p[i]+dp[i+1][1]);
                }
                else{
                    profit=max(dp[i+1][buy], p[i]+dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }
        return dp[0][0];
    }
};