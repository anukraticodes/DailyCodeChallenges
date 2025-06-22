class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i=0;
        while(i<s.size()){
            string a="";
            for(int j=0; j<k; j++){
                
                a+=s[i];
                i++;
                if(i==s.size()) break;
            }
            ans.push_back(a);
        }
        while(ans[ans.size()-1].size()<k){
            ans[ans.size()-1]+=fill;
        }
        return ans;
    }
};