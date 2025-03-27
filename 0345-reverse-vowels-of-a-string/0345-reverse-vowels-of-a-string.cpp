class Solution {
public:
    string reverseVowels(string s) {
        vector<bool> v(128, 0);
        for(auto c:"aeiouAEIOU"){
            v[c]=true;
        }
        int i=0, j=s.size()-1;
        while(i<j){
            while(i<j && !v[s[i]]) i++;
            while(i<j && !v[s[j]]) j--;
            if(i<j) swap(s[i++], s[j--]);
        }
        return s;
    }
};