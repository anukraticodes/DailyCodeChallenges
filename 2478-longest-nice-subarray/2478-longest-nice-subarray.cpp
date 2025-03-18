class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0, bitmask=0, l=0;
        for(int r=0; r<nums.size(); r++){
           while((bitmask&nums[r])!=0){
            bitmask^=nums[l];
            l++;
           }
           bitmask|=nums[r];
           ans=max(ans,r-l+1);
        }
        return ans;
    }
};