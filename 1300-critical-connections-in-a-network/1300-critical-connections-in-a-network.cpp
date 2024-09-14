class Solution {
public:
    int timer = 1;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
       
        vector<vector<int>> adj(n);
        for (int i = 0; i < c.size(); i++) {
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }

        
        vector<int> vis(n, 0), t(n, -1), low(n, -1);
        vector<vector<int>> bridges; 

        
        dfs(0, -1, adj, vis, t, low, bridges);
        return bridges;
    }

    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>& t, vector<int>& low, vector<vector<int>>& bridges) {
        vis[node] = 1;
        t[node] = low[node] = timer++;  

        for (auto it : adj[node]) {
            if (it == parent) continue; 

            if (!vis[it]) {
                
                dfs(it, node, adj, vis, t, low, bridges);

               
                low[node] = min(low[node], low[it]);

                
                if (low[it] > t[node]) {
                    bridges.push_back({node, it});  
                }
            } else {
               
                low[node] = min(low[node], t[it]);
            }
        }
    }
};
