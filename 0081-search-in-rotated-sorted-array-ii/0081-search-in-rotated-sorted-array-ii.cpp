class Solution {
public:
    int search(vector<int>& nums, int target) {
        int val=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]) val=i+1;
        }
        int ans1=bs(nums, 0, val-1, target);
        if(ans1!=-1) return 1;
        int ans2=bs(nums, val, nums.size()-1, target);
        return ans2!=-1?1:0;
    }

    int bs(vector<int>& nums,int low, int high, int target){
        // int low=0, high=nums.size()-1, ind=-1;

        while(low<=high){
            int mean=low+(high-low)/2;
            if(nums[mean]==target) return mean;
            if(nums[mean]>target) return bs(nums, low, mean-1, target);
            else return bs(nums, mean+1, high, target);
        }
        return -1;
    }
};