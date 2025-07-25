class Solution {
    private:
    vector<int> nums;
public:

    Solution(vector<int>& nums) {
        this->nums.swap(nums);
    }
    
    int pick(int target) {
        vector<int> arr;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target) arr.push_back(i);
        }
        int size = arr.size();
        

    int randomIndex = rand() % size;

    int randomValue = arr[randomIndex];
    return randomValue;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */