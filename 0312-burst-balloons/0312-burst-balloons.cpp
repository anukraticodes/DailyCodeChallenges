class Solution {
public:

    int helper(vector<vector<int>>& dp, vector<int>& nums, int i, int j){
        int n=nums.size();
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
    for (int k = i; k <= j; k++) {
        int coins = nums[i-1] * nums[k] * nums[j+1] 
                    + helper(dp, nums, i, k-1) 
                    + helper(dp, nums, k+1, j);
        ans = max(ans, coins);
    }
    return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> nnums;
        nnums.push_back(1);
        for(auto n:nums) nnums.push_back(n);
        nnums.push_back(1);
        int m=nnums.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return helper(dp, nnums, 1, m-2);
    }
};