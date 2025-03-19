class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int ans=bs(nums, low, high, target);
        return ans;
    }

    int bs(vector<int>& nums, int low, int high, int target){
        while(low<=high){
            int mean=low+(high-low)/2;
            if(nums[mean]==target) return mean;
            if(nums[mean]>target) return bs(nums, low, mean-1, target);
            else return bs(nums, mean+1, high, target);
        }
        return -1;
    }
};