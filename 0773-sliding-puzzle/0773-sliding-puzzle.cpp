class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> target = {{1,2,3},{4,5,0}};
        set<vector<vector<int>>> st;
        int ans = INT_MAX;
        queue<pair<vector<vector<int>>, int>> q;
        q.push({board, 0});
        st.insert(board);
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [sg, dep] = q.front();
            q.pop();
            if (sg == target) {
                ans = dep;
                break;
            }
            vector<vector<int>> mat(2, vector<int>(3));
            int x = -1, y = -1;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    if (sg[i][j] == 0) {
                        x = i, y = j;
                    }
                }
            }
            for (int i = 0; i < 4; i++) {
                int dx = x + dir[i], dy = y + dir[i + 1];
                if (dx >= 0 && dx < 2 && dy >= 0 && dy < 3) {
                    int curr = sg[dx][dy];
                    vector<vector<int>> mat=sg;
                    swap(mat[x][y], mat[dx][dy]);
                    if (!st.count(mat)){
                        st.insert(mat);
                        q.push({mat, dep + 1});
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};