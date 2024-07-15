class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int maxf=0; int r=0; int l=0; int len=INT_MIN;
        for(r=0; r<s.size(); r++){
            mp[s[r]]++;
            maxf=max(maxf, mp[s[r]]);

            if((r-l+1)-maxf>k){
                mp[s[l]]--;
                l++;
            }
            else{
                len=max(len, r-l+1);
            }
        }
        
        return len;
    }
};