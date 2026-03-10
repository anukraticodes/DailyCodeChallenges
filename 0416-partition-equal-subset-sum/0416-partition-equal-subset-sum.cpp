class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return 0;
        int k=sum/2;
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return helper(dp, nums, n, k);
    }

    int helper(vector<vector<int>>& dp, vector<int>& nums, int i, int j){
        if(j==0) return true;
        if(i==0) return false;

        if(dp[i][j]!=-1) return dp[i][j];

        int nottake=helper(dp, nums, i-1, j);
        int take=0;
        if(nums[i-1]<=j) take=helper(dp, nums, i-1, j-nums[i-1]);

        return dp[i][j]=take||nottake;

    }
};