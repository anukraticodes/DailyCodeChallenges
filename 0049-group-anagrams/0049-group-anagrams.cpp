class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        set<pair<string, int>> v;
        for(int i=0; i<strs.size(); i++){
            string word=strs[i];
            sort(word.begin(), word.end());
            v.insert({word, i});
        }
        string prev=(*v.begin()).first;
        vector<vector<string>> ans;
        vector<string> p;
        for(auto i:v){
            if(i.first!=prev){
                ans.push_back(p);
                p.clear();
                prev=i.first;
            }
            p.push_back(strs[i.second]);
        }
        ans.push_back(p);
        return ans;
    }
};