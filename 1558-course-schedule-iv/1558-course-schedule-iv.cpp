class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<int> indegree(n,0);
        vector<bool> ans;
        vector<vector<int>> adj(n);
        for(int i=0; i<p.size(); i++){
            adj[p[i][0]].push_back(p[i][1]);
        }
        for(int i=0; i<adj.size(); i++){
            for(int j=0; j<adj[i].size(); j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int> qu;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) qu.push(i);
        }
        
        unordered_map<int, unordered_set<int>> mp;
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
        
            for(int nbr:adj[node]){
                mp[nbr].insert(node);
                for(auto pre:mp[node]) mp[nbr].insert(pre);
                if(--indegree[nbr]==0) qu.push(nbr);
            }
        }
        
        for(int i=0; i<q.size(); i++){
            ans.push_back(mp[q[i][1]].contains(q[i][0]));
        }
        return ans;        
    }
};