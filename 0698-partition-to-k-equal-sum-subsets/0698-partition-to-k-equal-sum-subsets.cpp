class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask] == -1) continue;
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i)) && dp[mask] + nums[i] <= target) {
                    int newMask = mask | (1 << i);
                    dp[newMask] = (dp[mask] + nums[i]) % target;
                    if (dp[newMask] == 0 && newMask == (1 << n) - 1) return true;
                }
            }
        }  
        return dp[(1 << n) - 1] == 0;
    }
};