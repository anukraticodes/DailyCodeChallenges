class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size()<k) return 0;
        int ans=0;
        for(int u=1; u<=26; u++){
            int l=0; unordered_set<char> cnt;
            unordered_map<char, int> freq;
            for(int r=0; r<s.size(); r++){
              freq[s[r]]++;
              if(!cnt.count(s[r]) && freq[s[r]]>=k) cnt.insert(s[r]);
              while(freq.size()>u && l<r){
                freq[s[l]]--;
                if(cnt.count(s[l]) && freq[s[l]]<k) cnt.erase(s[l]);
                if(freq[s[l]]==0) {freq.erase(s[l]);}
                l++;
              }
              if(cnt.size()==u && freq.size()==u) ans=max(ans, r-l+1); 
            }
        }
        return ans;
    }
};