class Solution {
public:

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& fire, queue<tuple<int, int,int>>& q){
         
         vector<int> drc={-1, 0, 1, 0, -1};
         while(!q.empty()){
            auto [x, y, time]=q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int dx=x+drc[k], dy=y+drc[k+1];
                if(dx>=0 && dy>=0 && dx<grid.size() && dy<grid[0].size() && grid[dx][dy]==0&& fire[dx][dy]>time+1){
                    fire[dx][dy]=time+1;
                    q.push({dx, dy, time+1});
                }
            }
         }
    }

    bool ispossible(int t, vector<vector<int>>& fire, vector<vector<int>>& grid){
 
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        if(fire[0][0]<=t) return 0;
           queue<tuple<int, int, int>> q;
           q.push({0, 0, t});
           vis[0][0]=1;
           vector<int> drc={-1, 0, 1, 0, -1};
           while(!q.empty()){
             auto[x,y,time]=q.front();
             q.pop();
             
             for(int k=0; k<4; k++){
                int dx=x+drc[k], dy=y+drc[k+1];
                if(dx>=0 && dy>=0 && dx<grid.size() && dy<grid[0].size() && grid[dx][dy]==0 && !vis[dx][dy]){
                    if(dx==grid.size()-1 && dy==grid[0].size()-1 && fire[dx][dy]>=time+1) return 1;
                    if(fire[dx][dy]>time+1){
                    q.push({dx, dy, time+1});
                    vis[dx][dy]=1;
                    }
                }
             }

           }
           return 0;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        vector<vector<int>> fire(grid.size(), vector<int>(grid[0].size(), 1e9));
        queue<tuple<int, int, int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    q.push({i, j, 0});
                    fire[i][j]=0;
                }
            }
        }
        bfs(grid, fire, q);
        for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (fire[i][j] == 1e9)
                fire[i][j] = INT_MAX;
        }
    }
        int ans=-1;
        int l=0, r=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            if(ispossible(mid, fire, grid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans; 
    }
};