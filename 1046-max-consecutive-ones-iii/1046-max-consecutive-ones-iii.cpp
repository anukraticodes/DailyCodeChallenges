class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0,cnt=0;
        int ans=INT_MIN;
        for(r=0; r<nums.size(); r++){
            if(nums[r]==0) cnt++;
            while(cnt>k){
                if(nums[l]==0) cnt--;
                l++;
            }
            if(cnt<=k) ans=max(ans, r-l+1);
        }
        return ans;
    }
};