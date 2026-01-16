class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0, ans=INT_MIN;
        int mf=0;
        unordered_map<char, int> mp;
        for(int r=0; r<n; r++){
            mp[s[r]]++;
            mf=max(mf, mp[s[r]]);
            while(((r-l+1)-mf)>k && l<=r){
              if(mp[s[l]]==1) mp.erase(s[l]);
              else mp[s[l]]--;
              l++;
            }
            ans=max(ans, r-l+1);
        }
        return ans;
    }
};