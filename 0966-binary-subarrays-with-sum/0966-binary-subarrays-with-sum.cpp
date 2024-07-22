class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int, int> mp;
        mp[0]=1;
        int sum=0, cnt=0;
        for(int num:nums){
            sum+=num;
            if(mp.find(sum-goal)!=mp.end())
            cnt+=mp[sum-goal];

            mp[sum]++;
        }
        return cnt;
    }
};