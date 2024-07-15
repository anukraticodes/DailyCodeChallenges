class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int maxf=0; int r=0; int l=0; int len=INT_MIN;
        while(r<s.size()){
            mp[s[r]]++;
            maxf=max(maxf, mp[s[r]]);

            while((r-l+1)-maxf>k){
                mp[s[l]]--;
                l++;
            }
            
                len=max(len, r-l+1);
            r++;
        }
        
        return len;
    }
};