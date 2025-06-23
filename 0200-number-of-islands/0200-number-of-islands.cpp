class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // vector<vector<bool>> vis(n, vector<bool>(m, 0));

        int cnt = 0;
        vector<int> drc = {-1, 0, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        grid[p.first][p.second] = '0';
                        for (int k = 0; k < 4; k++) {
                            int nr = p.first + drc[k],
                                nc = p.second + drc[k + 1];
                            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == '1') {
                                grid[nr][nc] = '0';
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};