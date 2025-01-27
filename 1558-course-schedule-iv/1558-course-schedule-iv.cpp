class Solution {
public:

    bool dfs(vector<vector<int>>& adj, int u, int v, vector<bool>& vis){
        // int n=vis.size();
        vis[u]=1;
        for(auto nbr: adj[u]){
            if(nbr==v) return true;
            if (!vis[nbr] && dfs(adj, nbr, v, vis)) return true;
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<vector<int>> adj(n);
        for(int i=0; i<p.size(); i++){
            adj[p[i][0]].push_back(p[i][1]);
        }
        vector<bool> ans(q.size(), 0);
        
        for(int i=0; i<q.size(); i++){
            vector<bool> vis(n,0);
            if(dfs(adj,q[i][0], q[i][1],vis)) ans[i]=1;
        }
        return ans;
              
    }
};