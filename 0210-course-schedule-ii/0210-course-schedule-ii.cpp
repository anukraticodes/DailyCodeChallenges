class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
      vector<int> v;
      if(n<=0) return {};

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
        int vertex=q.front();
        q.pop();
        v.push_back(vertex);
        vector<int> children= adj[vertex];
        for (int child : adj[vertex]) {
                inDegree[child]--;
                if (inDegree[child] == 0) q.push(child);
            }
      }

      if(v.size()!=n) v.clear();
      return v;
    }
};