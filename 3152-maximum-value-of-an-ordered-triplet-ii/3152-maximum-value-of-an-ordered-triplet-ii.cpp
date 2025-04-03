class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long val=0, maxi=0, dmax=0;
        for(int i=0; i<nums.size(); i++){
            val=max(val, dmax*nums[i]);
            dmax=max(dmax, maxi-nums[i]);
            maxi=max(maxi, (long long)nums[i]);
        }
        return val;
    }
};