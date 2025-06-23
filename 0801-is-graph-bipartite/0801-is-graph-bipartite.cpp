class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<pair<int, bool>> q;
        vector<bool> color(graph.size());
        vector<int> vis(graph.size(), 0);
        for(int i=0; i<graph.size(); i++){
             if(!vis[i]){
                q.push({i, 0});
                while(!q.empty()){
                    int node=q.front().first;
                    bool clr=q.front().second;
                    q.pop();
                    for(auto it:graph[node]){
                        if(vis[it] && color[it]==clr) return 0;
                        else if(!vis[it]){
                            vis[it]=1;
                            color[it] = !clr;
                            q.push({it, !clr});
                        }
                    }
                }
             }
        }
        return 1;
    }
};