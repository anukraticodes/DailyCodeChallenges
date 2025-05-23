class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto n:arr) mp[n]++;
        unordered_set<int> st;
        for(auto it:mp) st.insert(it.second);
        unordered_set<int> st2(arr.begin(), arr.end());
        return st.size()==st2.size();
    }
};