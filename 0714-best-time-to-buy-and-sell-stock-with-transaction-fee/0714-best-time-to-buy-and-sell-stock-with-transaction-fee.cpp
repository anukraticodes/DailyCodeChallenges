class Solution {
public:

    int helper(vector<vector<int>>& dp, vector<int>& p, int ind, bool buy, int fee){
        if(ind==p.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy==0){
            profit=max(helper(dp, p, ind+1, 0, fee), -p[ind]+helper(dp, p, ind+1, 1, fee));
        }
        else{
            profit=max(helper(dp, p, ind+1, 1, fee), p[ind]-fee+helper(dp, p, ind+1, 0, fee));
        }
        return dp[ind][buy]=profit;
    }

    int maxProfit(vector<int>& p, int fee) {
        int n=p.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(dp, p, 0, 0, fee);
    }
};