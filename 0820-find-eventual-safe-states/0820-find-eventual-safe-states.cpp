class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> term;
        int n=graph.size();
         vector<vector<int>> reverseGraph(n);
        vector<int> inDegree(graph.size(),0);
        
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
                inDegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDegree[i]==0) q.push(i);
        }
        vector<int> v;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            v.push_back(node);
            for(auto nbr:reverseGraph[node]){
                 inDegree[nbr]--;
                 if(inDegree[nbr]==0) q.push(nbr);
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};