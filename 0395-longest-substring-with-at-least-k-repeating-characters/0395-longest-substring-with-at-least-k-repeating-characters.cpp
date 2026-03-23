class Solution {
public:
    
    int longestSubstring(string s, int k) {
        int ans=0;
        for(int i=0; i<s.size(); i++){
            map<char, int> mp;
            for(int j=i; j<s.size(); j++){
                mp[s[j]]++; bool flag=0;
                for(auto it:mp){
                   if(it.second<k) flag=1;
                }
                if(flag==0) ans=max(ans, j-i+1);
            }
        }
        return ans;
    }
};