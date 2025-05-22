class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt=0;
        int prod=1;
        int r=0, l=0;
        while(r<nums.size() && l<=r){
            prod*=nums[r];
            while(prod>=k && l<=r){
                prod/=nums[l];
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
};