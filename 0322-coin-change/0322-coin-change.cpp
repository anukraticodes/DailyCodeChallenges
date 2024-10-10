class Solution {
public:
long long helper(vector<int>& coins, int i,vector<vector<long long>>& dp, int amount){
        if(i==0){
          if(amount%coins[i]==0) return amount/coins[i];
          return INT_MAX; 
        } 
        if(dp[i][amount]!=-1) return dp[i][amount];
        long long nottake= helper(coins, i-1, dp, amount);
        long long take=INT_MAX;
        if(coins[i]<=amount) take=1+helper(coins, i, dp, amount-coins[i]);
        return dp[i][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        long long n=coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1, -1));
        long long ans=helper(coins, n-1, dp, amount);
        if(ans==INT_MAX) return -1;
        else return ans;
    }

    
};