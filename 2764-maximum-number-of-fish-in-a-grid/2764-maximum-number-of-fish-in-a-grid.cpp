class Solution {
public:

    struct DSU{
        vector<int> parent, rank;
        DSU(int n){
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0; i<n; i++) parent[i]=i;
        }

        int find(int n){
            if(parent[n]!=n) parent[n]=find(parent[n]);
            return parent[n];
        }

        void unite(int u, int v){
            int pu=find(u), pv=find(v);
            if(pu!=pv){
                if(rank[pu]>rank[pv]) parent[pv]=pu;
                else if(rank[pu]<rank[pv]) parent[pu]=pv;
                else{
                    parent[pu]=pv;
                    rank[pv]++;
                }
            }
        }
    };

    int dfs(int row, int col, vector<vector<bool>>& vis,vector<vector<int>>& grid, int& cnt){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        cnt+=grid[row][col];
        int drc[5]={-1,0,1,0,-1};
        for(int i=0; i<4; i++){
            int nrow=row+drc[i];
            int ncol=col+drc[i+1];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]!=0){
                dfs(nrow, ncol, vis, grid,cnt);
            }
        }
        return cnt;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0 && !vis[i][j]){
                     int cnt = 0;
                dfs(i, j, vis, grid, cnt);
                ans = max(ans, cnt);
                }
            }
        }
        return ans;        
    }
};