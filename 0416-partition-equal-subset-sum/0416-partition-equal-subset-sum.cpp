class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        for(int i=0; i<n; i++){
            target+=nums[i];
        }
        if(target%2!=0) return false;
        int sum=target/2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return helper(n-1, nums, dp, sum);
        }

        bool helper(int i,vector<int>& nums, vector<vector<int>>& dp, int sum){
            if(sum==0) return true;
            if(i==0) return nums[0]==sum;
            if(dp[i][sum]!=-1) return dp[i][sum];
            bool nottaken=helper(i-1,nums,dp,sum);
            bool taken=0;
            if(nums[i]<=sum)taken=helper(i-1,nums,dp,sum-nums[i]);
            return dp[i][sum]=taken||nottaken;

        }
    
};