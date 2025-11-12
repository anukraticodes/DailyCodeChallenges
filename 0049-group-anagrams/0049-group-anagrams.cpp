class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> neww=strs;
        map<string, vector<int>> mp;
        for(int i=0; i<strs.size(); i++){
            sort(neww[i].begin(), neww[i].end());
            mp[neww[i]].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it:mp){
            vector<string> p;
            for(auto it2:it.second){
                p.push_back(strs[it2]);
            }
            ans.push_back(p);
        }
        return ans;
    }
};