class Solution {
public:

    int helper(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        int n=nums.size();
        if(i>j) return 0;
        if(i==j){
            int temp=nums[i];
            if(i-1>=0) temp*=nums[i-1];
            if(i+1<n) temp*=nums[i+1];
            return temp;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int k=i; k<=j; k++){
            int temp=nums[k];
            if(j+1<n) temp*=nums[j+1];
            if(i-1>=0) temp*=nums[i-1];
            temp+=(helper(nums, i, k-1, dp)+helper(nums, k+1, j, dp));
            ans=max(temp, ans);
        }
        return dp[i][j]=ans;
    }

    int maxCoins(vector<int>& nums) {
      
        vector<int> arr={1};
        for(auto n:nums) arr.push_back(n);
        arr.push_back(1);
        vector<vector<int>> dp(501, vector<int>(501, -1));
        int n=arr.size();
        return helper(arr, 1, n-2, dp);
    }
};