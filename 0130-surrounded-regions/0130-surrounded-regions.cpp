class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return; // Edge case for empty board
        int m = board[0].size();
        queue<pair<int, int>> q;

        // Direction vectors for up, right, down, left
        int drc[5] = {-1, 0, 1, 0, -1};

        // Start from all 'O's on the borders and mark them as safe using BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O') {
                    q.push({i, j});
                    board[i][j] = '#'; // Mark as visited and safe
                }
            }
        }

        // BFS to mark all connected 'O's from the border
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drc[i];
                int ncol = col + drc[i + 1];
                // Ensure within bounds and find connected 'O's
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && board[nrow][ncol] == 'O') {
                    board[nrow][ncol] = '#'; // Mark as visited and safe
                    q.push({nrow, ncol});
                }
            }
        }

        // Second pass to flip 'O' to 'X' and '#' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
