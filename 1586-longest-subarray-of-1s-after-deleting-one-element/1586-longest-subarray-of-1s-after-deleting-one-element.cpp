class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt=0;
        int ans=0;
        int l=0, r=0;
        for(r=0; r<nums.size(); r++){
            if(nums[r]==0) cnt++;
            while(cnt>=2 && l<=r){
                if(nums[l]==0) cnt--;
                l++;
            }
            ans=max(ans, r-l+1);
        }
        return ans-1;
    }
};