class Solution {
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(int i=0; i<f.size(); i++){
            adj[f[i][0]].push_back({f[i][1], f[i][2]});
        }

        vector<int> ans(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0,0}});
        ans[src]=0;

        while(!q.empty()){
            int curr=q.front().first;
            int stops=q.front().second.first;
            int price=q.front().second.second;
            q.pop();

            for(auto vertex: adj[curr]){
              if((price + vertex.second < ans[vertex.first])&& k>=stops){
                ans[vertex.first]=price+vertex.second;
                q.push({vertex.first, {stops+1, price+vertex.second}});
              }
            }
        }
        if(ans[dst]>=INT_MAX) return -1;
        return ans[dst];



    }
};