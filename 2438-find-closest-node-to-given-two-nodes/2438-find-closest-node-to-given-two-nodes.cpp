class Solution {
public:

    void bfs(int node, vector<int>& dist, vector<int>& edges){
        queue<pair<int, int>> q;
        vector<bool> vis(dist.size(), 0);
        q.push({node, 0});
        
        while(!q.empty()){
           auto [curr, d]=q.front();
           q.pop();
           vis[curr]=1;
           dist[curr]=d;
           if(edges[curr]!=-1 && !vis[edges[curr]])
           q.push({edges[curr], d+1});
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1(edges.size(), INT_MAX), dist2(edges.size(), INT_MAX);
        bfs(node1, dist1, edges);
        bfs(node2, dist2, edges);
        int ind=-1;
        int lowest=INT_MAX;
        for(int i=0; i<edges.size(); i++){
            if(dist1[i]!=INT_MAX && dist2[i]!=INT_MAX){
                if(max(dist1[i], dist2[i])<lowest){
                    lowest=max(dist1[i], dist2[i]);
                    ind=i;
                }
            }
        }
        return ind;
    }
};