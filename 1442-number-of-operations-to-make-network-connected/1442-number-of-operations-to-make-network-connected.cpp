class Solution {
public:
vector<int> parent, rank;

void disjoint(int n){
    rank.resize(n);
    parent.resize(n);
    for(int i=0; i<n; i++){
        parent[i]=i;
        rank[i]=0;
    }
}

void join(int u, int v){
    int pu=findP(u);
    int pv=findP(v);
    if(rank[pu]>rank[pv]){
        parent[pv]=pu;
    }
    else if(rank[pv]>rank[pu]){
        parent[pu]=pv;
    }
    else{
        parent[pu]=pv;
        rank[pv]++;
    }
}

int findP(int u){
    if(parent[u]==u) return u;
    return parent[u]=findP(parent[u]);
}



    int makeConnected(int n, vector<vector<int>>& c) {
        disjoint(n);
        if((c.size())<n-1) return -1;
        int cnt=0;
        for(int i=0; i<c.size(); i++){
            join(c[i][0], c[i][1]);
        }
        for(int i=0; i<n; i++){
            if(parent[i]==i)cnt++;
        }
        return cnt-1;

    }
};