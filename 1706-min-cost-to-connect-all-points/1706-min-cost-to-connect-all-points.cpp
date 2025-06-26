class Solution {
public:
    vector<int> parent, rank;
    void createDsu(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }

    void unionDsu(int u, int v){
        int pu=findParent(u), pv=findParent(v);
        if(pu==pv) return;
        if(rank[pu] > rank[pv]){
        parent[pv] = pu;
    } else if(rank[pu] < rank[pv]){
        parent[pu] = pv;
    } else {
        parent[pu] = pv;
        rank[pv]++;
    }
    }


    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        vector<tuple<int, int, int>> v;
        for(int i=0; i<points.size()-1; i++){
            int x=points[i][0], y=points[i][1];
            for(int j=i+1; j<points.size(); j++){
                int x1=points[j][0], y1=points[j][1];
                int dist=abs(x-x1)+abs(y-y1);
                v.push_back({dist, i, j});
            }
        }
        int sum=0;
        set<tuple<int, int, int>> st(v.begin(), v.end());
        createDsu(points.size());
        while(!st.empty()){
            auto[wt, u, v]=*st.begin();
            st.erase(*st.begin());
            if(findParent(u)!=findParent(v)){
                unionDsu(u, v);
                sum+=wt;
            }
        }
        return sum;
    }
};