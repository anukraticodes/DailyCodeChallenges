class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        int n = board.size(), m = board[0].size();
        int r = click[0], c = click[1];
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<pair<int, int>> dirs = {{-1, 0},  {0, 1},  {1, 0}, {0, -1},
                                       {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int cnt = countmines(board, x, y);
            if (cnt > 0)
                board[x][y] = cnt + '0';
            else {
                board[x][y] = 'B';
                for (auto it : dirs) {
                    int dx = x + it.first, dy = y + it.second;
                    if (dx >= 0 && dx < n && dy >= 0 && dy < m &&
                        board[dx][dy] == 'E') {
                        board[dx][dy] = 'B';
                        q.push({dx, dy});
                    }
                }
            }
        }
        return board;
    }

    int countmines(vector<vector<char>>& board, int r, int c) {
        vector<pair<int, int>> dirs = {{-1, 0},  {0, 1},  {1, 0}, {0, -1},
                                       {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
        int cnt = 0;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < 8; i++) {
            int dx = r + dirs[i].first;
            int dy = c + dirs[i].second;
            if (dx >= 0 && dx < n && dy >= 0 && dy < m && board[dx][dy] == 'M')
                cnt++;
        }
        return cnt;
    }
};