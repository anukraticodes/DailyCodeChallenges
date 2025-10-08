class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (n == 0) return {-1, -1};

        int st  = helper1(nums, target); // last index < target
        int end = helper2(nums, target); // first index > target

        int L = st + 1;
        int R = end - 1;

        if (L <= R && L >= 0 && R < n && nums[L] == target && nums[R] == target)
            return {L, R};
        return {-1, -1};
    }

    // last index with value < target
    int helper1(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size() - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                ans = mid;          // valid (< target)
                l = mid + 1;        // push right to find last <
            } else {
                r = mid - 1;        // nums[mid] >= target
            }
        }
        return ans; // -1 if none <
    }

    // first index with value > target
    int helper2(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size() - 1, ans = (int)nums.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                ans = mid;          // valid (> target)
                r = mid - 1;        // pull left to find first >
            } else {
                l = mid + 1;        // nums[mid] <= target
            }
        }
        return ans; // n if none >
    }
};
