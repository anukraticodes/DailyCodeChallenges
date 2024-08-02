class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n1=count(nums.begin(), nums.end(), 1);
        int mswap=INT_MAX, cnt1=0;
        int r=0, l=0;
        for(r=0; r<nums.size()+n1; r++){
            cnt1+=nums[r%nums.size()];
            if(r-l+1>n1) cnt1-=nums[l++ % nums.size()];
            if(r-l+1 == n1) mswap=min(mswap, n1-cnt1);
        }
        return mswap;
    }
};