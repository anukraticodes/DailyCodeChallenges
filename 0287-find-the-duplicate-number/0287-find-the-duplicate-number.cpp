class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int num:nums){
            int ind=abs(num);
            if(nums[ind]<0) return ind;
            nums[ind]=-nums[ind];
        }
        return n;
    }
};