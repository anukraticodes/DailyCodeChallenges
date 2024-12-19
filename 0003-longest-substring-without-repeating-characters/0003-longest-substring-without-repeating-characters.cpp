class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        if(s=="") return 0;
        int l=0, r=0, len=INT_MIN;
        while(r<s.size()){
            mp[s[r]]++;
            if(mp[s[r]]>1){
               while(mp[s[r]]!=1){
               mp[s[l]]--;l++ ;}
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};