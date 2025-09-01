class Solution {
public:
    vector<int> parent, rank;

    void dsu(int n){
      parent.resize(n);
      rank.resize(n, 0);
      for(int i=0; i<n; i++){
        parent[i]=i;
      }
    }

    int findP(int u){
        if(parent[u]==u) return parent[u];
        else return parent[u]=findP(parent[u]);
    }

    void merge(int u, int v){
        int pu=findP(u);
        int pv=findP(v);
        if(pu==pv) return;
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pu]<rank[pv]) parent[pu]=pv;
        else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& c) {
        int n1=c.size();
        if(n1<n-1) return -1;
        dsu(n);
        int cnt=0;
        for(int i=0; i<c.size(); i++){
            merge(c[i][0], c[i][1]);
        }
        for(int i=0; i<n; i++){
            if(parent[i]==i) cnt++;
        }
        return cnt-1;
    }
};