class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_map<char,int> mp;
        int l=0,r=0,ans=0;
        while(r<s.size()){
            char curr=s[r];
            while(mp.count(curr) && l<r){
                mp.erase(mp[s[l]]);
                l++;
            }
            ans=max(ans, r-l+1);
            mp[curr]++;
            r++;
        }
        if(l!=s.size()-1) ans=max(ans, r-l+1);
        return ans;
    }
};