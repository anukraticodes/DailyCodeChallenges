class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int, int>>> adj(n);
        int k=0;
        for(int i=0; i<n; i++){
            int x=points[i][0], y=points[i][1];
        for(int j=0; j<n; j++){
            if(points[i]==points[j]) continue;
            int x1=points[j][0], y1=points[j][1];
            int dist=abs(x-x1)+abs(y-y1);
            adj[i].push_back({j, dist});
        }
        }
        int sum=0;
        vector<bool> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            sum+=wt;
            for(auto nbr:adj[node]){
                if(!vis[nbr.first]){
                    pq.push({nbr.second, nbr.first});
                }
            }
        }
        return sum;
    }
};