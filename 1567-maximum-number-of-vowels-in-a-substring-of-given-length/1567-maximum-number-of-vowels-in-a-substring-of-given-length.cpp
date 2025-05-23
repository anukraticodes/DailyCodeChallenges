class Solution {
public:

    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    int maxVowels(string s, int k) {
        int cnt=0, ans=0;
        for(int i=0; i<k; i++) if(isVowel(s[i])) cnt++;
        ans=max(ans, cnt);
        // int l=0, r=k;
        int l = 0;
        for(int r = k; r < s.size(); r++) {
            if(isVowel(s[r])) cnt++;   
            if(isVowel(s[l])) cnt--;     
            l++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};