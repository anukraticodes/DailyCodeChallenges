class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        vector<vector<int>> t(c, vector<int>(r, 0));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                t[j][i]=grid[i][j];
            }
        }
        map<vector<int>, int> mp;
        for(auto v:grid){
            mp[v]++;
        }
        int cnt=0;
        for(auto v:t){
            if(mp.find(v)!=mp.end()) cnt+=mp[v];
        }
        return cnt;
    }
};