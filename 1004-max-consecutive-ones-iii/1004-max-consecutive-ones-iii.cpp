class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int l=0;
        int cnter=0;
        for(int r=0; r<nums.size(); r++){
            if(nums[r]==0) cnter++;
            while(cnter>k && l<=r){
                if(nums[l]==0) cnter--;
                l++;
            }
            ans=max(ans, r-l+1);
        }
        return ans;
    }
};