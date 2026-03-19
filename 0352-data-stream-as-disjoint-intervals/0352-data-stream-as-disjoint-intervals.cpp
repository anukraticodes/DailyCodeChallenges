struct DSU{
        vector<int> parent, rank;
        DSU(int n){
           parent.resize(n);
           rank.resize(n,0);
           for(int i=0; i<n; i++) parent[i]=i;
        }

        int findP(int u){
            if(parent[u]!=u) return parent[u]=findP(parent[u]);
            return parent[u];
        }

        void unite(int u, int v){
            int pv=findP(v), pu=findP(u);
            if(pu==pv) return;
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
    };

class SummaryRanges {
public:

    DSU dsu;
    unordered_set<int> st;

    SummaryRanges() : dsu(10001) {
        
    }
    
    void addNum(int value) {
        if(st.count(value)) return;
        if(st.count(value-1)){
            dsu.unite(value, value-1);
        }
        if(st.count(value+1)){
            dsu.unite(value, value+1);
        }
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        map<int, set<int>> mp;
        for(auto it:st){
            int p=dsu.findP(it);
            mp[p].insert(it);
        }
        for(auto it:mp){
            auto v=it.second;
            if(v.size()==1){
            int val=*v.begin();
               ans.push_back({val, val});
            }
            else{
            int f=*v.begin();
            int s=*v.rbegin();
            ans.push_back({f,s});
            }
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */