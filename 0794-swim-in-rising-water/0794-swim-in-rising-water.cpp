class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({grid[0][0],0,0});
        int drc[5]={-1,0,1,0,-1};
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vis[0][0]=1;
        int ans=0;
        while(!pq.empty()){
            auto [h,r,c]=pq.top();
            pq.pop();
            ans=max(ans, h);
            if(r==n-1 &&c==m-1) return ans;
            for(int i=0; i<4; i++){
                int nr=r+drc[i], nc=c+drc[i+1];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
     return ans;
    }
};