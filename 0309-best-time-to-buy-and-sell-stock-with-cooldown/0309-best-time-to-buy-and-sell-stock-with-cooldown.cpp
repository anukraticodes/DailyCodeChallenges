class Solution {
public:

    int helper(vector<vector<vector<int>>>& dp, vector<int>& p, int ind, bool buy, bool cooldown){
        if(ind==p.size()) return 0;
        if(dp[ind][buy][cooldown]!=-1) return dp[ind][buy][cooldown];
        int profit=0;
        if(buy==0){
            if (cooldown)
                profit = helper(dp, p, ind + 1, 0, 0);
            else
            profit=max(helper(dp, p, ind+1, 0, 0), -p[ind]+helper(dp, p, ind+1, 1, 0));
        }
        else{
            profit=max(helper(dp, p, ind+1, 1, 0), p[ind]+helper(dp, p, ind+1, 0, 1));
        }
        return dp[ind][buy][cooldown]=profit;
    }

    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return helper(dp, p, 0, 0, 0);
    }
};