class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int ans=bs(nums, low, high, target);
        if(ans==-1){
            return insert(nums, target);
        }
        return ans;
    }

    int bs(vector<int>& nums,int low, int high, int target){
        while(low<=high){
            int mean=low+(high-low)/2;
            if(nums[mean]==target) return mean;
            if(nums[mean]>target) return bs(nums, low, mean-1, target);
            else return bs(nums, mean+1, high, target);
        }
        return -1;
    }

    int insert(vector<int>& nums, int target){
        if(nums[0]>target) return 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]<target && nums[i+1]>target) return i+1;
        }
        return nums.size();
    }
};