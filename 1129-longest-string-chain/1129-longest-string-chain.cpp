class Solution {
public:
    bool helper(const string& s1, const string& s2) {
    if (s2.length() != s1.length() + 1) return false;

    int i = 0, j = 0;
    bool usedExtra = false;

    while (i < s1.length() && j < s2.length()) {
        if (s1[i] == s2[j]) {
            i++; j++;
        } else {
            if (usedExtra) return false;
            usedExtra = true;
            j++; 
        }
    }
    return true;
}

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [&] (string a, string b){
           return a.size()<b.size();
        });
        int n=words.size();
        vector<int> dp(words.size(), 1);
        for(int i=0; i<n; i++){
           for(int prev=0; prev<i; prev++){
            if(helper(words[prev],words[i]) && 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
            }
           }
        }
        return *max_element(dp.begin(), dp.end());

    }
};