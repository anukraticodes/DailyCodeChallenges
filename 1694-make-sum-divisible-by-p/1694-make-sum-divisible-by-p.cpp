class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % p == 0) return 0;
        int rem = sum % p;

        unordered_map<int, int> prefix;
        long long prefixsum = 0;
        prefix[0] = -1;
        int minlen = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefixsum = (prefixsum + nums[i]) % p;
            int target = (prefixsum - rem + p) % p;
            if (prefix.find(target) != prefix.end()) {
                minlen = min(minlen, i - prefix[target]);
            }
            prefix[prefixsum] = i;
        }
        return minlen == nums.size() ? -1 : minlen;
    }
};
