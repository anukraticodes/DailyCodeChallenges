class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref(nums.size(),0), suff(nums.size());
        int prod=1; pref[0]=1; suff[nums.size()-1]=1;
        for(int i=0; i<nums.size()-1; i++){
            prod*=nums[i];
            pref[i+1]=prod;
        }
        prod=1;
        for(int i=nums.size()-1; i>0; i--){
            prod*=nums[i];
            suff[i-1]=prod;
        }
        vector<int> ans(nums.size());
        for(int i=0; i<nums.size(); i++){
            ans[i]=(pref[i]*suff[i]);
        }
        return ans;
    }
};