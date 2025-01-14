class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l=0, r=0;
        unordered_set<string> st;
        vector<string> result;
        unordered_set<string> ans;
        for(r=9; r<s.size(); r++){
            // cout<<s.substr(l,r-l+1)<<endl;
            if(st.contains(s.substr(l,r-l+1))){
                 ans.insert(s.substr(l,r-l+1));
            }
            st.insert(s.substr(l, r-l+1));
            l++;
        }
        for(string val:ans){
            result.push_back(val);
        }

        return result;
    }
};