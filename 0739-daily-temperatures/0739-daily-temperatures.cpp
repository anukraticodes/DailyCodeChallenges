class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size());
        unordered_map<int, int> mp;
        stack<pair<int, int>> st;
        st.push({temp[0], 0});
        for(int i=0; i<temp.size(); i++){
            while(!st.empty()&&temp[i]>st.top().first){
                mp[st.top().second]=i-st.top().second;
                st.pop();
            }
            st.push({temp[i], i});
        }
        while(!st.empty()){
            mp[st.top().second]=0;
            st.pop();
        }
        for(auto it:mp){
           ans[it.first]=it.second;
        }
        return ans;
    }
};