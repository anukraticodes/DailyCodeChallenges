class Solution {
public:
   int target;
   double res=0.0;

   void dfs(vector<vector<int>>& adj, int node, int time, double p, vector<bool>& vis, int t){
    vis[node]=1;
    if(time>t) return;
    if(node==target){
        if(time==t || (adj[node].size() == 1 && node != 0)){
        res=p;
        }
        return;
    }
       
       int n=0;
       for(auto nbr:adj[node]){
        if(!vis[nbr]) n++;
       }
       for(auto nbr:adj[node]){
        if(!vis[nbr])
        dfs(adj, nbr, time+1, p*(1.0/n), vis, t);
       }
       
   }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n==1) return 1;
        this->target=target-1;
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0], v=it[1];
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        vector<bool> vis(n, 0);
        
        dfs(adj, 0, 0, 1.0, vis, t);
        return res;
    }
};