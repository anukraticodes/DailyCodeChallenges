class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(helper(nums, 0, nums.size()-2), helper(nums, 1, nums.size()-1));
    }

    int helper(vector<int>&nums, int start, int end){
        int prev=0, rob=0;
        for(int i=start; i<=end; i++){
            int temp=max(rob, prev+nums[i]);
            prev=rob;
            rob=temp;
        }
        return rob;
    }
};