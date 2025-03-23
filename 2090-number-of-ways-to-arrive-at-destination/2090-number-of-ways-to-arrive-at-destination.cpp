class Solution {
public:
int countPaths(int n, vector<vector<int>>& roads) {
    const int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> adj(n);
    
    for (auto& road : roads) {
        int u = road[0], v = road[1], wt = road[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<long long> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[0] = 0;
    ways[0] = 1; 
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue; 

        for (auto [nbr, wt] : adj[node]) {
            if (dist[nbr] > d + wt) {
                dist[nbr] = d + wt;
                ways[nbr] = ways[node];  
                pq.push({dist[nbr], nbr});
            } else if (dist[nbr] == d + wt) {
                ways[nbr] = (ways[nbr] + ways[node]) % MOD;
            }
        }
    }

    return ways[n - 1];
}
};