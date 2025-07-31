class Solution {
public:

    int helper(vector<vector<int>>& dp, vector<int>& p, int ind, bool buy){
        if(ind>=p.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy==0){
            profit=max(helper(dp, p, ind+1, 0), -p[ind]+helper(dp, p, ind+1, 1));
        }
        else{
            profit=max(helper(dp, p, ind+1, 1), p[ind]+helper(dp, p, ind+2, 0));
        }
        return dp[ind][buy]=profit;
    }

    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(dp, p, 0, 0);
    }
};