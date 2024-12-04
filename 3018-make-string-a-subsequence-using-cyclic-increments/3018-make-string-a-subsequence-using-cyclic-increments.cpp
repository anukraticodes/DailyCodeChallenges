class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int l=str2.size();
        int ind=0;
        for(auto c:str1){
            if(ind<l && (str2[ind]-c+26)%26<=1) ind++;
        }
        return ind==l;
    }
};