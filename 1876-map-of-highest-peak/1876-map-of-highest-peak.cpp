class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        vector<int> drc = {1, 0, -1, 0, 1};
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        int cnt = 1;
        while (!q.empty()) {
            int ls = q.size();
            for (int i = 0; i < ls; i++) {
                auto [x1, y1] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int x = x1 + drc[d];
                    int y = y1 + drc[d + 1];
                    if (x >= 0 && y >= 0 && x < n && y < m && ans[x][y] == -1) {
                        ans[x][y] = cnt;
                        q.push({x, y});
                    }
                }
            }
            cnt++;
        }

        return ans;
    }
};
