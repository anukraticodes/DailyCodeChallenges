class Solution {
public:

    int helper(vector<vector<int>>& dp, vector<int>& nums, int ind, int prev){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int take, nottake;
        nottake=helper(dp, nums, ind+1, prev);
        if(prev==-1 || nums[ind]>nums[prev]) take=1+helper(dp, nums, ind+1, ind);
        
        return dp[ind][prev+1]=max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return helper(dp, nums, 0, -1);
    }
};