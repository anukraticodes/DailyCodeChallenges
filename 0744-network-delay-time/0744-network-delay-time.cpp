class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0; i<t.size(); i++){
            adj[t[i][0]].push_back({t[i][1], t[i][2]});
        }
        queue<pair<int, int>> q;
        vector<int> ans(n+1, INT_MAX);
        q.push({k,0});
        ans[k]=0;
        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            for(auto vertex: adj[node]){
                if((time+ vertex.second)< ans[vertex.first]){
                    ans[vertex.first]=time+vertex.second;
                    q.push({vertex.first, time+vertex.second});
                }
            }
        }
        int maxTime = 0;
        for(int i = 1; i <= n; i++){
            if(ans[i] == INT_MAX) return -1; 
            maxTime = max(maxTime, ans[i]);
        }

        return maxTime;
    }
};