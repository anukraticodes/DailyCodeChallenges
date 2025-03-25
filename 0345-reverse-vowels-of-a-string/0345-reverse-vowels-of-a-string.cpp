class Solution {
public:

    bool isVowel(char c){
        return c=='a' || c=='i' || c=='e' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' ||c=='O'||c=='U';
    }
 
    string reverseVowels(string s) {
        vector<char> v;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i]))v.push_back(s[i]);
        }
        string ans="";
        int j=0;
        reverse(v.begin(), v.end());
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])) ans+=v[j++];
            else ans+=s[i];
        }
        return ans;
    }
};