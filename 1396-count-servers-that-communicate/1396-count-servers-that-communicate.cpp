class Solution {
public:
       struct DSU{
        vector<int> parent, rank;
        DSU(int n){
            parent.resize(n);
            rank.resize(n, 0);
            for(int i=0; i<n; i++) parent[i]=i;
        }

        int find(int node){
            if(parent[node]!=node) parent[node]=find(parent[node]);
            return parent[node];
        }

        void unite(int u, int v){
            int pu=find(u), pv=find(v);
            if(pu!=pv){
                if(rank[pu]>rank[pv]) parent[pv]=pu;
                else if(rank[pv]>rank[pu]) parent[pu]=pv;
                else{
                    parent[pu]=pv;
                    rank[pv]++;
                }
            }
        }
    };

    int countServers(vector<vector<int>>& g) {
        vector<pair<int, int>> grid;
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<g[0].size(); j++){
                if(g[i][j]==1) grid.push_back({i, j});
            }
        }
        DSU dsu(grid.size());
        int n=grid.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(grid[i].first==grid[j].first || grid[i].second==grid[j].second)
                dsu.unite(i,j);
            }
        }
        
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            int x=dsu.find(i);
            mp[x].push_back(i);
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second.size()>1) cnt+=it.second.size();
        }
        return cnt;
    }
};