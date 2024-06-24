
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0; // Count of flips
        int flip = 0; // To track the current state of flips
        vector<int> flipped(n, 0); // Auxiliary array to track flips

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flip ^= flipped[i - k];
            }
            if (nums[i] == flip) {
                if (i + k > n) return -1; // Not enough elements to flip
                flip ^= 1;
                flipped[i] = 1;
                cnt++;
            }
        }

        return cnt;
    }
};
