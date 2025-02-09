class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long, long long> mp;
        long long cnt=0;
        long long n=nums.size();
        for(long long i=0; i<nums.size(); i++){
            long long x=nums[i]-i;
            if(mp.find(x)!=mp.end()) cnt+=mp[x];
            mp[x]++;
        }
        return (n*(n-1))/2-cnt;
    }
};