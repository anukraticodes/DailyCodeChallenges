class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string s = "";
        string target = "123450";
        unordered_set<string> st;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                s += board[i][j]+'0';
            }
        }
        int ans = INT_MAX;
        queue<pair<string, int>> q;
        q.push({s, 0});
        st.insert(s);
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [sg, dep] = q.front();
            q.pop();
            if (sg == target) {
                ans = dep;
                break;
            }
            vector<vector<int>> mat(2, vector<int>(3));
            int k = 0, x = -1, y = -1;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    if (sg[k] == '0') {
                        x = i, y = j;
                    }
                    mat[i][j] = sg[k++] - '0';
                }
            }
            for (int i = 0; i < 4; i++) {
                int dx = x + dir[i], dy = y + dir[i + 1];
                if (dx >= 0 && dx < 2 && dy >= 0 && dy < 3) {
                    int curr = mat[dx][dy];
                    string s1 = "";
                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < 3; j++) {
                            if (i == dx && j == dy)
                                s1 += "0";
                            else if (mat[i][j] == 0)
                                s1 += curr + '0';
                            else
                                s1 += mat[i][j]+'0';
                        }
                    }
                    if (!st.count(s1)){
                        st.insert(s1);
                        q.push({s1, dep + 1});
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};