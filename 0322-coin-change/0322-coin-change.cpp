class Solution {
public:
long long helper(vector<int>& coins,vector<vector<long long>>& dp, int amount){
        for(int i=0; i<=amount; i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i] = LLONG_MAX;
        }
        for(int i=1; i<coins.size(); i++){
            for(int j=0; j<=amount; j++){
                long long nottake=dp[i-1][j];
                long long take =LLONG_MAX;
                if(coins[i]<=j && dp[i][j - coins[i]] != LLONG_MAX) take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take,nottake);
            }
        }
        return dp[coins.size()-1][amount];


    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount+1, -1));
        long long ans=helper(coins, dp, amount);
        if (ans >= LLONG_MAX) return -1;
        else return ans;
    }

    
};