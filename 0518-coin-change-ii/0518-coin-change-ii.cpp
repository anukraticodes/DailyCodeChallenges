class Solution {
public:
    int helper(vector<int>& coins, int i,vector<vector<int>>& dp, int amount){
        if(amount == 0) return 1;
        // If no coins left or amount becomes negative, no valid way exists
        if(i < 0 || amount < 0) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        
        // Two options: don't take or take the current coin
        int notTake = helper(coins, i - 1, dp, amount);
        int take = 0;
        if(coins[i] <= amount) take = helper(coins, i, dp, amount - coins[i]);
        
        // Total number of ways to form the amount
        return dp[i][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        long long n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return helper(coins, n-1, dp, amount);
       
    }   
};