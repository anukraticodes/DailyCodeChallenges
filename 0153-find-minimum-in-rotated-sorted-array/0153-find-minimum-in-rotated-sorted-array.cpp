class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[l]==nums[mid] && nums[l]==nums[r]) return nums[mid];
            else if(nums[l]>=nums[mid] && nums[r]>=nums[mid]){
                if((r-l+1)==2) return nums[l];
                l++; r--;
            }
            else if(nums[l]<=nums[mid] && nums[mid]>=nums[r]) l=mid+1;
            else r=mid-1;
        }
        return 0;
    }
};