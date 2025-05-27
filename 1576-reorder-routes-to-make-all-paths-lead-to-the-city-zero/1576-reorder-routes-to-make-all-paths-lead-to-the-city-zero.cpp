class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        set<pair<int, int>> directed;

        // Build graph
        for (auto &conn : connections) {
            int u = conn[0], v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            directed.insert({u, v}); // mark original direction
        }

        vector<bool> visited(n, false);
        int count = 0;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    if (directed.count({node, neighbor})) {
                        count++; 
                    }
                    dfs(neighbor);
                }
            }
        };

        dfs(0);
        return count;
    }
};
