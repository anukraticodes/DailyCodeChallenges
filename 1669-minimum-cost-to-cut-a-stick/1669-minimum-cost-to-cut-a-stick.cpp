class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0); cuts.push_back(n);
        int m=cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for(int len=2; len<m; len++){
            for(int i=0; i+len<m; i++){
                int j=i+len;
                int ans=INT_MAX;
                for(int mid=i+1; mid<j; mid++){
                    int c=dp[i][mid]+dp[mid][j]+cuts[j]-cuts[i];
                    ans=min(ans, c);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][m-1];
    }
};