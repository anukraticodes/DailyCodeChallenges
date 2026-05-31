class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans=0;
        fn(0, s.size()-1, s, ans, k);
        return ans;
    }

    void fn(int st, int e, string& s, int& ans, int k){
        unordered_map<char, int> mp;
        for(int i=st; i<=e; i++) mp[s[i]]++;
       for(int i=st; i<=e; i++){
          if(mp[s[i]]<k){
            fn(st, i-1, s, ans, k);
            fn(i+1, e, s,ans, k);
            return ;
          }
       }
       ans=max(ans, e-st+1);
    }
};