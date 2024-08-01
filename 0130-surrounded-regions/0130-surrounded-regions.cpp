class Solution {
public:
    void solve(vector<vector<char>>& b) {
        int n=b.size();
        int m=b[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && b[i][j]=='O'){
                     dfs(i, j, b, vis);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(b[i][j]=='O'&& !vis[i][j]){
                    b[i][j]='X';
                }
            }
        }
    }

    void dfs(int row, int col, vector<vector<char>>& b, vector<vector<bool>> &vis){
        int n=b.size();
        int m=b[0].size();
        vis[row][col]=1;
        int drc[5]={-1, 0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nrow=row+drc[i];
            int ncol=col+drc[i+1];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && b[nrow][ncol]=='O'){
                dfs(nrow, ncol, b, vis);
            }
        }
    }
};