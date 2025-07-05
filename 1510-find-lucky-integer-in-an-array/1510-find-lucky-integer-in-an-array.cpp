class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans=-1;
        map<int, int> mp;
        for(auto n:arr) mp[n]++;
        for(auto it:mp){
            if(it.first==it.second) 
            ans=it.first;
        }
        return ans;
    }
};