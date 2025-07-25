class Solution {
    private:
    unordered_map<int, vector<int>> ind;
public:

    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            this->ind[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size=ind[target].size();
        return ind[target][rand()%size];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */