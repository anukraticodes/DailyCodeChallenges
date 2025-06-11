class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        if (target == 0) return nums.size();  // edge case: remove all
        if (target < 0) return -1;

        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0, maxLen = -1;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (mp.count(sum - target)) {
                maxLen = max(maxLen, i - mp[sum - target]);
            }
            if (!mp.count(sum)) {
                mp[sum] = i;
            }
        }

        return maxLen == -1 ? -1 : nums.size() - maxLen;
    }
};
