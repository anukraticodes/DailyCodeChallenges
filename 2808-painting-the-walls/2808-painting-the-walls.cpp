int dp[501];
class Solution {
public:
int paintWalls(vector<int>& cost, vector<int>& time) {
    fill_n(begin(dp), cost.size() + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < cost.size(); ++i)
        for (int j = cost.size(); j > 0; --j)
            dp[j] = min(dp[j], dp[max(0, j - time[i] - 1)] + cost[i]);
    return dp[cost.size()];
}
};