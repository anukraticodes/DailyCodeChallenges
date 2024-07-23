class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> mp;
        int r=0, l=0, cnt=0;
        while(r<s.size()){
            mp[s[r]]++;
            while(mp['a']>=1&&mp['b']>=1&&mp['c']>=1){
                cnt+=(s.size()-r);
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};