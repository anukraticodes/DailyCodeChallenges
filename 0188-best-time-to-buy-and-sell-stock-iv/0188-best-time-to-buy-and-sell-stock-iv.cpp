class Solution {
public:

    int helper(vector<vector<vector<int>>>& dp, vector<int>& p, int cap, int ind, bool buy){
        if(ind==p.size()||cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit=0;
        if(buy==0){
            profit=max(helper(dp, p, cap, ind+1, buy), -p[ind]+helper(dp, p, cap, ind+1, 1));
        }
        else{
            profit=max(helper(dp, p, cap, ind+1, buy), p[ind]+helper(dp, p, cap-1, ind+1, 0));
        }
        return dp[ind][buy][cap]=profit;
    }

    int maxProfit(int k, vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return helper(dp, p, k, 0, 0);
    }
};