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
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 0, p, dp);
    }
};