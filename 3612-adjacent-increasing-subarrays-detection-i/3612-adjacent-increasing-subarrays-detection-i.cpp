class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        if (k == 1) return true;

        // Case 1: exactly two subarrays of length k
        if (n == 2 * k) {
            bool flag = false;
            for (int j = 0; j < k - 1; j++) { // fix: only till k-2
                if (nums[j] >= nums[j + 1] || nums[j + k] >= nums[j + k + 1]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) return true;
        } 
        // Case 2: sliding window for more than two subarrays
        else {
            for (int i = 0; i <= n - 2 * k; i++) {
                bool flag = false;
                for (int j = 0; j < k - 1; j++) {
                    if (nums[i + j] >= nums[i + j + 1] || nums[i + k + j] >= nums[i + k + j + 1]) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) return true;
            }
        }
        return false;
    }
};
