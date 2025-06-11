class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]=1;
        int cnt=0, sum=0;
        for(int i=0; i<nums.size(); i++){
            sum=(sum+nums[i])%k;
            if(sum<0) sum+=k;
            if(mp.count(sum)) cnt+=mp[sum];
            mp[sum]++;
        }
        return cnt;
    }
};