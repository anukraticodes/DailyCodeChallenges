class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt=0;
        map<int, int> mp;
        mp[0]=1;
        int prefixsum=0;
        for(int i=0; i<nums.size(); i++){
            prefixsum=(prefixsum+nums[i])%k;
            if(prefixsum<0) prefixsum+=k;
            if(mp.find(prefixsum)!=mp.end()){
                 cnt+=mp[prefixsum];
            }
            mp[prefixsum]++;
        }
        return cnt;
    }
};