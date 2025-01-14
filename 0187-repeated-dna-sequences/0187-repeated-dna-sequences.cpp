class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        int l=0;
        for(int r=9; r<s.size(); r++){
            mp[s.substr(l,r-l+1)]++;
            l++;
        }
        vector<string> ans;
        for(unordered_map<string, int> ::iterator it=mp.begin(); it!=mp.end(); it++){
            if(it->second>1) ans.push_back(it->first);
        }
        return ans;
    }
};