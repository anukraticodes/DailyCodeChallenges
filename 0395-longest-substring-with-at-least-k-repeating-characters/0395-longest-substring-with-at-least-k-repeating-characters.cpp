class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, k, 0, s.size());
    }

    int helper(string s, int k, int st, int e){
        if(e-st<k) return 0;

        vector<int> freq(26, 0);
        for(int i=st; i<e; i++) freq[s[i]-'a']++;

        for(int i=st; i<e; i++){
            if(freq[s[i]-'a']<k){
                int l=helper(s, k, st, i);
                int r=helper(s, k, i+1, e);
                return max(l, r);
            }
        }
        return e-st;
    }
};