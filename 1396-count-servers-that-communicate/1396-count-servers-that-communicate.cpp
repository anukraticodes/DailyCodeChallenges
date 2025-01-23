class Solution {
public:
       struct DSU {
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int node) {
            if (parent[node] != node) 
                parent[node] = find(parent[node]);
            return parent[node];
        }

        void unite(int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu != pv) {
                if (rank[pu] > rank[pv]) 
                    parent[pv] = pu;
                else if (rank[pu] < rank[pv]) 
                    parent[pu] = pv;
                else {
                    parent[pu] = pv;
                    rank[pv]++;
                }
            }
        }
    };

   int countServers(vector<vector<int>>& g) {
    // Store the positions of all servers
    vector<pair<int, int>> grid;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[0].size(); j++) {
            if (g[i][j] == 1) grid.push_back({i, j});
        }
    }

    int n = grid.size();  // Total number of servers
    if (n == 0) return 0; // If no servers, return 0

    DSU dsu(n); // Create a DSU for the servers

    // Unite servers in the same row or column
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (grid[i].first == grid[j].first || grid[i].second == grid[j].second) {
                dsu.unite(i, j);
            }
        }
    }

    // Group servers by their root parent
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int root = dsu.find(i);
        mp[root].push_back(i);
    }

    // Count servers in connected components with size > 1
    int cnt = 0;
    for (auto it : mp) {
        if (it.second.size() > 1) {
            cnt += it.second.size();
        }
    }
    return cnt;
}

};