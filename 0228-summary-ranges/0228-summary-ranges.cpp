class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        int l=0, r=0;
        for(int r = 0; r < nums.size(); r++) {
        if(r == nums.size() - 1 || nums[r+1] != nums[r] + 1) {
            if(l == r) {
                ans.push_back(to_string(nums[l]));
            } else {
                ans.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
            }
            l = r + 1;
        }
    }
        return ans;
    }
};