class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        string s="";
        for(char c:searchWord){
            s+=c;
            vector<string> v;
            for(int i=0; i<products.size(); i++){
                if(s==products[i].substr(0, s.size())){
                    v.push_back(products[i]);
                }
                if(v.size()==3) break;
            }
            ans.push_back(v);
        }
        return ans;
    }
};