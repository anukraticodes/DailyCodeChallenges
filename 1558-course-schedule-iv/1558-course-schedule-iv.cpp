class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        // Initialize reachability matrix
        vector<vector<bool>> reachable(n, vector<bool>(n, false));

        // Mark direct prerequisites
        for (const auto& edge : p) {
            reachable[edge[0]][edge[1]] = true;
        }

        // Transitive closure using Floyd-Warshall
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
                }
            }
        }

        // Answer queries
        vector<bool> ans;
        for (const auto& query : q) {
            ans.push_back(reachable[query[0]][query[1]]);
        }

        return ans;
    }
};
