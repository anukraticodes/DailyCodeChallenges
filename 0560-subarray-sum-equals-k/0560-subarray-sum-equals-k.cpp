class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cnt=0;
        vector<int> prefix(nums.size());
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            prefix[i]=sum;
            mp[sum]=i;
        }
        for(int i=0; i<nums.size(); i++){
            if(mp.find(abs(prefix[i]-k))!=mp.end()) {
                if(mp[abs(prefix[i]-k)]!=i) cnt++;
            }
            else if(prefix[i]==k) cnt++;
        }
        return cnt;
    }
};