class Solution {
public:
    int appendCharacters(string s, string t) {
        if(s==t) return 0;
        int cnt=0;
        int k=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==t[k]){
               cnt++;
               k++;
            }
        }
        return t.size()-cnt;
    }
};