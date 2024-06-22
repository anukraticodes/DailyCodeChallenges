class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(nums.size()<k) return -1;
        vector<int> cnt(nums.size()+1, 0);
        cnt[0]=1;
        int ans=0, t=0;
        for(int ele:nums){
            t+=ele&1;
            if(t-k>=0) ans+=cnt[t-k];
            cnt[t]++;
        }
        return ans;
    }
};