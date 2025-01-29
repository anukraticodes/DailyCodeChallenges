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
        int pu=find(pu), pv=find(v);
        if(pu!=pv){
            if(rank[pu]>rank[pv]) parent[pv]=pu;
            else if(rank[pu]<rank[pv]) parent[pu]=pv;
            else{
                parent[pu]=pv;
                rank[pv]++;
            }
        }
    }
};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        pair<int, int> p;
        for(auto edge:edges){
            if(dsu.find(edge[0]-1)!=dsu.find(edge[1]-1)) dsu.unite(edge[0]-1, edge[1]-1);
            else p={edge[0], edge[1]};
        }
        vector<int> ans;
        ans.push_back(p.first);
        ans.push_back(p.second);
        return ans;
    }
};