class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        
        int m = board[0].size();
        queue<pair<int, int>> q;

        
        int drc[5] = {-1, 0, 1, 0, -1};

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O') {
                    q.push({i, j});
                    board[i][j] = '#'; 
                }
            }
        }

        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drc[i];
                int ncol = col + drc[i + 1];
                
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && board[nrow][ncol] == 'O') {
                    board[nrow][ncol] = '#'; 
                    q.push({nrow, ncol});
                }
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
