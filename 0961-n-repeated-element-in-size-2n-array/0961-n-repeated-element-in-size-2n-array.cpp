class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> mp;
        for(auto it:nums){
            if(mp.count(it)) return it;
            mp.insert(it);
        }
        return *mp.begin();
    }
};