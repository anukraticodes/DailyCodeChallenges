class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
        auto it=A.begin();
        sort(it, A.end());
        vector<vector<string>> ans;
        string curr="";
        for(char c:searchWord){
            curr+=c;
            vector<string> v;
            it=lower_bound(it, A.end(), curr);
            for(int i=0; i<3 && it+i!=A.end(); i++){
                string& s=*(it+i);
                if(s.find(curr)) break;
                v.push_back(s);
            }
            ans.push_back(v);
        }
        return ans;
    }
};