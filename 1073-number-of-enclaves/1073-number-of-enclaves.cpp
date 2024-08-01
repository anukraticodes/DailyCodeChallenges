class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0||j==0||i==n-1||j==m-1)&& grid[i][j]==1)
                dfs(i, j, grid, vis);
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1&& vis[i][j]==0)
                cnt++;
            }
        }
        return cnt;
    }

    void dfs(int row, int col,vector<vector<int>>& grid,vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        int drc[5]={-1, 0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nrow=row+drc[i];
            int ncol=col+drc[i+1];
            if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&& grid[nrow][ncol]==1&& vis[nrow][ncol]==0){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
};