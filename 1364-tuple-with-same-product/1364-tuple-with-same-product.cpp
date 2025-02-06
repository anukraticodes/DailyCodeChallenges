class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int cnt=0;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        for(auto it:mp) {
            cnt+=(it.second-1)*(it.second)/2;
        }
        return cnt*8;
    }
};