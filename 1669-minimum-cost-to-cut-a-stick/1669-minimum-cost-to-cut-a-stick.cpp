class Solution {
public:

    int helper(int l, int r, vector<vector<int>>& dp, vector<int>& newCuts){
        if(dp[l][r]!=-1) return dp[l][r];
        if(r-l==1) return 0;
        int ans = INT_MAX;
        for (int mid = l + 1; mid < r; mid++) {
            int c =helper(l, mid, dp, newCuts) + helper(mid, r, dp, newCuts) + newCuts[r] - newCuts[l];
            ans = min(ans, c);
        }
        dp[l][r] = ans;
        return ans;
    }

    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        cuts.push_back(0); cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m+2, vector<int>(m+2, -1));
        return helper(0, m+1, dp, cuts);

    }
};