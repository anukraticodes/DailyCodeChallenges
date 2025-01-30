class Solution {
public:
    bool bipartite(int n, vector<vector<int>>& adj) {
        vector<bool> vis(n, false);
        vector<int> colour(n, -1);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            q.push(i);
            vis[i] = true;
            colour[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nbr : adj[node]) {
                    if (colour[nbr] == -1) {
                        colour[nbr] = 1 - colour[node];
                        vis[nbr] = true;
                        q.push(nbr);
                    } else if (colour[nbr] == colour[node]) {
                        return false; // Conflict detected
                    }
                }
            }
        }
        return true;
    }

    int getDistance(int n, vector<vector<int>>& adj, int node) {
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(node);
        vis[node] = true;
        int distance = 0;

        while (!q.empty()) {
            int no = q.size();
            for (int i = 0; i < no; i++) {  // Process only current level
                int curr = q.front();
                q.pop();

                for (auto nbr : adj[curr]) {
                    if (!vis[nbr]) {
                        vis[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            distance++; // Increment level after processing all nodes at the current level
        }
        return distance;
    }

    int groups(vector<vector<int>>& adj, int node, vector<int>& distances, vector<bool>& vis) {
        queue<int> q;
        q.push(node);
        vis[node] = true;
        int maxg = distances[node];

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto nbr : adj[curr]) {
                if (!vis[nbr]) {
                    vis[nbr] = true;
                    maxg = max(maxg, distances[nbr]); // Get max level
                    q.push(nbr);
                }
            }
        }
        return maxg;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }
        if (!bipartite(n, adj)) return -1;

        vector<int> distances(n);
        for (int node = 0; node < n; node++) {
            distances[node] = getDistance(n, adj, node);
        }

        int maxg = 0;
        vector<bool> vis(n, false);
        for (int node = 0; node < n; node++) {
            if (vis[node]) continue;
            maxg += groups(adj, node, distances, vis);
        }

        return maxg;
    }
};
