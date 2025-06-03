class Solution {
public:
vector<string> v;
vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return ans;
        }
        v.resize(10);
        int j=0;
        for(int i=2; i<=7; i++){
            string s="";
           for(int k=0; k<3; k++) {
            s+=(j+'a');
            j++;
           }
           v[i]=s;
        }
        v[7]+='s';
        j++;
        for(int i=8; i<=9; i++) {
            string s="";
            for(int k=0; k<3; k++) {
            s+=(j+'a');
            j++;
            }
            v[i]=s;
        }
        v[9]+='z';
        
       helper(digits, 0, "");
       return ans;
    }

    void helper(string digits, int ind, string s){
        if(ind==digits.size()) {ans.push_back(s);
        return;
        }
        string letter=v[digits[ind]-'0'];
        for(char it:letter){
            helper(digits, ind+1, s+it);
        }
    }
};