class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<multiset<char>, vector<int>> mp;
        for(int i=0; i<strs.size(); i++){
            multiset<char> st;
            for(int j=0; j<strs[i].size(); j++){
               st.insert(strs[i][j]);
            }
            mp[st].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it:mp){
            vector<string> push;
            for(auto it2:it.second){
                push.push_back(strs[it2]);
            }
            ans.push_back(push);
        }
        return ans;
    }
};