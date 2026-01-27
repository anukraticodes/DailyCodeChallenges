class Solution {
public:
   int minCost(int n, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj(n);
    for(auto it:edges){
        int u=it[0], v=it[1], w=it[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, 2*w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> vis(n, 0);
    vector<int> minCost(n, INT_MAX);
    vis[0] = 1;
    minCost[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [w, node] = pq.top();
        pq.pop();
        if (w > minCost[node]) continue;
        for (const auto& nbr : adj[node]) {
            int v = nbr.first;
            int wt = nbr.second;
            if (minCost[node] + wt < minCost[v]) {
                minCost[v] = minCost[node] + wt;
                pq.push({minCost[v], v});
            }
        }
    }
    return minCost[n - 1] == INT_MAX ? -1 : minCost[n - 1];
}
};