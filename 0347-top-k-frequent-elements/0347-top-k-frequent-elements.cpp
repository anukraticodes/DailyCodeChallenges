class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto n:nums) mp[n]++;
        priority_queue<pair<int, int>> pq;
        for(auto it:mp){
            int freq=it.second, element=it.first;
            pq.push({freq,element});
        }
        vector<int> ans;
       for(int i=0; i<k; i++){
            int element=pq.top().second;
            ans.push_back(element);
            pq.pop();
        }
        return ans;
    }
};