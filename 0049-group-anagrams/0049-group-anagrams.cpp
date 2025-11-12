class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<int>> mp;
        for(int i=0; i<strs.size(); i++){
            string word=strs[i];
            sort(word.begin(), word.end());
            mp[word].push_back(i);
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