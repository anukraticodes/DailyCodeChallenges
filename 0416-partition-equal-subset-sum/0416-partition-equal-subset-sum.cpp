class Solution {
public:
    int helper(vector<vector<int>>& dp, int i, int j, vector<int>& nums){
        if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        bool nottake=helper(dp, i-1, j, nums);
        bool take=0;
        if(nums[i-1]<=j) take=helper(dp, i-1, j-nums[i-1], nums);
        return dp[i][j]=take||nottake;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return 0;
        int k=sum/2;
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return helper(dp,n,k,nums);
    }
};