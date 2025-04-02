class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        int start=0, end=0;
        int maxl=1;

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));
        for(int i=0; i<s.size(); i++){
            dp[i][i]=1;
            for(int j=0; j<i; j++){
                if(s[i]==s[j] && (i-j<=2 || dp[j+1][i-1])){
                    dp[j][i]=1;
                    if(i-j+1>=maxl){
                        maxl=i-j+1;
                        start=j;
                        end=i;
                    }
                }
            }
        }
        return s.substr(start, maxl);
    }
};