class Solution {
public:
    static bool canPartition(const vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int s = sum / 2;
        bitset<20001> dp;
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i){
            dp |= dp << nums[i];
        }
        return dp[s];
    }
};