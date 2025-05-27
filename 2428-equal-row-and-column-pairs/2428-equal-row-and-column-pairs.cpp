class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows;
        map<vector<int>,int> cols;
        for(int i=0; i<grid.size(); i++){
            vector<int> v;
            for(int j=0; j<grid[0].size(); j++){
                v.push_back(grid[i][j]);
            }
            rows[v]++;
        }
        for(int i=0; i<grid[0].size(); i++){
            vector<int> v;
            for(int j=0; j<grid.size(); j++){
                v.push_back(grid[j][i]);
            }
            cols[v]++;
        }
        int cnt=0;
        for (auto r : rows) {
    if (cols.find(r.first) != cols.end()) {
        cnt += r.second * cols[r.first];
    }
}

        return cnt;

    }
};