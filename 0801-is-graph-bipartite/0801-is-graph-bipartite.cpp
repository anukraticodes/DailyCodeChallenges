class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<pair<int, bool>> q;
        vector<bool> vis(n, 0);
        vector<bool> color(n);
        for(int i=0; i<n; i++){
          if(vis[i]==0) q.push({i,0});
        
        while(!q.empty()){
            auto[node, c]=q.front();
            q.pop();
            vis[node]=1;
            color[node]=c;
            for(auto nbr:graph[node]){
                 if(!vis[nbr]){
                    q.push({nbr, !c});
                }
                else if(color[nbr]==c) return false;
            }
        }}
        return true;
    }
};