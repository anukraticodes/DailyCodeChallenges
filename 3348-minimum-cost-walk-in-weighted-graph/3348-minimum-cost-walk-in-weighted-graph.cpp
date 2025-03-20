class Solution {
public:
    vector<int> parent, height;

    int find(int node){
        if(parent[node]==-1) return node;
        return parent[node]=find(parent[node]);
    }

    void Union(int u, int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(height[pu]<height[pv]) swap(pu, pv);
        parent[pv]=pu;
        if(height[pu]==height[pv]) height[pu]++;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        parent.resize(n,-1);
        height.resize(n,0);
        vector<unsigned int> cost(n,-1);
        for(auto& edge:edges){
            Union(edge[0], edge[1]);
        }
        for(auto& edge: edges){
            int root=find(edge[0]);
            cost[root]&=edge[2];
        }
        vector<int> ans;
        for(auto& query: queries){
            int start=query[0];
            int end=query[1];
            if(find(start)!=find(end)) ans.push_back(-1);
            else{
                int root=find(start);
                ans.push_back(cost[root]);
            }
        }
        return ans;
    }
};