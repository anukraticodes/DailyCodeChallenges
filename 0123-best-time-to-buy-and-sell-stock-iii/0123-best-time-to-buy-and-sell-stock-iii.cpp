class Solution {
public:

    int helper(vector<vector<vector<int>>>& dp, vector<int>& p, int ind, int cap, bool buy){
        if(ind==p.size()|| cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        long profit=0;
        if(buy==0){
          profit=max(helper(dp, p, ind+1, cap, buy), -p[ind]+helper(dp, p, ind+1, cap, 1));
        }
        else{
            profit=max(helper(dp, p, ind+1, cap, buy), p[ind]+helper(dp, p, ind+1, cap-1, 0));
        }
        return dp[ind][buy][cap]=profit;
   }

    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>> dp(n, (vector<vector<int>>(2, vector<int>(3, -1))));
        return helper(dp, p, 0, 2, 0);
    }
};