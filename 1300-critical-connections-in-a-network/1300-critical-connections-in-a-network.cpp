class Solution {
public:
    int timer = 1;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        // Adjacency list for the graph
        vector<vector<int>> adj(n);
        for (int i = 0; i < c.size(); i++) {
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }

        // Visited, discovery time (t), and low values for each node
        vector<int> vis(n, 0), t(n, -1), low(n, -1);
        vector<vector<int>> bridges;  // Stores critical connections (bridges)

        // Run DFS starting from node 0
        dfs(0, -1, adj, vis, t, low, bridges);
        return bridges;
    }

    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>& t, vector<int>& low, vector<vector<int>>& bridges) {
        vis[node] = 1;
        t[node] = low[node] = timer++;  // Set discovery time and low-link value

        for (auto it : adj[node]) {
            if (it == parent) continue;  // Skip the parent node in DFS

            if (!vis[it]) {
                // DFS on unvisited child node
                dfs(it, node, adj, vis, t, low, bridges);

                // Update the low-link value of the current node
                low[node] = min(low[node], low[it]);

                // Check if the current edge is a bridge
                if (low[it] > t[node]) {
                    bridges.push_back({node, it});  // Save the critical connection
                }
            } else {
                // If already visited, update low-link value
                low[node] = min(low[node], t[it]);
            }
        }
    }
};
