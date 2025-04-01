class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size();
        vector<unordered_map<char, int>> dp(n+1);
        for(int i=n-1; i>=0; i--){
            dp[i]=dp[i+1];
            dp[i][t[i]]=i+1;
        }
       for (int i = 0; i < dp.size(); i++) {
        cout << "dp[" << i << "]: { ";
        for (const auto& pair : dp[i]) {
            cout << "'" << pair.first << "': " << pair.second << ", ";
        }
        cout << "}\n";
    }
        int i=0;
        for(char c:s){
            if(dp[i].count(c)) i=dp[i][c];
            else return 0;
        }
        return 1;
    }
};