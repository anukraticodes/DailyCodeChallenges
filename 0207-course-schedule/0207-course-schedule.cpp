class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        unordered_map<int, int> inDegree;
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            inDegree[i]=0;
            adj[i]={};
        }
        for(int i=0; i<p.size(); i++){
            adj[p[i][1]].push_back(p[i][0]);
            inDegree[p[i][0]]++;
        }
        queue<int> q;
        for(auto it=inDegree.begin(); it!=inDegree.end(); it++){
            if(it->second==0) q.push(it->first);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto vertex: adj[node]){
                inDegree[vertex]--;
                if(inDegree[vertex]==0) q.push(vertex);
            }
        }
        for(auto it=inDegree.begin(); it!=inDegree.end(); it++){
            if(it->second!=0) return false;
        }
        return true;
    }
};