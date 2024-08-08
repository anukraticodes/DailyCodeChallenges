class Solution {
public:

    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph){
        vis[node]=2;

        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, graph)) return true;
            }
            else if(vis[it]==2) return true;
        }
        vis[node]=1;
        return false;
        
    }   
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int> vis(n, 0);
       for(int i=0; i<n; i++){
        if(!vis[i])
        dfs(i, vis, graph);
       }
    
    vector<int> ans;

    for(int i=0; i<n; i++){
        if(vis[i]==1) ans.push_back(i);
    }
    return ans;
}
};