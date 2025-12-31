class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n+1, 0);
        for(int i=1; i<=nums.size(); i++){
          prefix[i]=prefix[i-1]+nums[i-1];
        }
        long long ans=0;
        for(int i=1; i<n; i++)
        {
            if(prefix[i]>=prefix[n]-prefix[i])ans++;
        }
        return (int)ans;
    }
};