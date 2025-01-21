class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long sum1=accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long sum2=0;
        long long ans=LONG_LONG_MAX;
        for(int i=0; i<grid[0].size(); i++){
            sum1-=grid[0][i];
            ans=min(ans, max(sum1, sum2));
            sum2+=grid[1][i];
        }
        return ans;
    }
};