class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        if (sum < abs(target) || (sum - target) % 2 != 0) return 0;
        
        int a = (sum - target) / 2;
        
        vector<vector<int>> dp(n, vector<int>(a + 1, 0));
        return helper(nums,a, dp);
    }

    int helper(vector<int>& nums, int a, vector<vector<int>>& dp ){
        int n=nums.size();
       
        if (nums[0] == 0) {
            dp[0][0] = 2;
        } else {
            dp[0][0] = 1; 
            if (nums[0] <= a) dp[0][nums[0]] = 1; 
        }

       
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= a; j++) {
                int notTake = dp[i - 1][j]; // Do not take the current element
                int take = 0;
                if (nums[i] <= j) {
                    take = dp[i - 1][j - nums[i]]; // Take the current element
                }
                dp[i][j] = take + notTake; // Total ways by taking and not taking
            }
        }

        // Return the number of ways to form sum `a`
        return dp[n - 1][a];
    }
};
