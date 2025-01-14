class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int l=0, r=0;
        int sum=0;
        for(r=0; r<nums.size(); r++){
            sum+=nums[r];
            while(sum>=target){
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;   
            }
        }
        return ans==INT_MAX?0:ans;
    }
};