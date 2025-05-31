class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> cells(n * n + 1, -1);
        bool leftToRight = true;
        int index = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    cells[index++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    cells[index++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }

        queue<int> q;
        vector<bool> visited(n * n + 1, false);
        q.push(1);
        visited[1] = true;
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int curr = q.front(); q.pop();
                if (curr == n * n) return steps;

                for (int i = 1; i <= 6; ++i) {
                    int next = curr + i;
                    if (next > n * n) continue;

                    if (cells[next] != -1) {
                        next = cells[next];
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
