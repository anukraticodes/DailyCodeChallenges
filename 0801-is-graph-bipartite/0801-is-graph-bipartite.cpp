class Solution {
public:

    bool dfs(int node, vector<bool>& vis, bool c, vector<bool>& colour, vector<vector<int>>& graph){
        vis[node]=1;
        colour[node]=c;
        for(auto nbr:graph[node]){
            if(!vis[nbr]){
                if(!dfs(nbr, vis, !c, colour, graph)) return false;
            }
            if(colour[nbr]==c) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n, 0);
        vector<bool> colour(n);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(!dfs(i, vis, 0, colour, graph)) return false;
            }
        }
        return true;
    }
};