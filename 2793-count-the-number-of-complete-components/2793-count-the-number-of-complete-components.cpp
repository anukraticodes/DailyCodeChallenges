class Solution {
public:
    vector<int> parent, height;
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    void dsu(int u, int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(height[pu]>height[pv]) parent[pv]=pu;
        else if(height[pv]>height[pu]) parent[pu]=pv;
        else{
            parent[pu]=pv;
            height[pv]++;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n), height.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            if(parent[edge[0]]!=parent[edge[1]]){
                dsu(edge[0], edge[1]);
            }
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // set<int> p;
        // for(int i=0; i<parent.size(); i++){
        //     if(parent[i]==i) p.insert(i);
        // }
        // int a=p.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<parent.size(); i++){
            mp[parent[i]].push_back(i);
        }
        int cnt = 0;
for (auto& it : mp) {  
    vector<int>& nodes = it.second;
    int size = nodes.size(); 
    bool isClique = true;
    for (int node : nodes) {
        if (adj[node].size() != size - 1) {  
            isClique = false;
            break;
        }
    }

    if (isClique) cnt++;  
}
        return cnt;
       
    }
};