class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int x=nums[0];
        int ans=-1;
      
        for(int i=1; i<nums.size(); i++){
           if(x>=nums[i]){
            x=nums[i];
           }
           else{
            ans=max(ans, nums[i]-x);
           }
        }
        return ans;
    }
};