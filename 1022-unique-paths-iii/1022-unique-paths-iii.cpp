class Solution {
public:

    void helper(vector<vector<int>>& grid, int r, int c, int zeroes, int cc, int& ans, int n, int m){
        if(r<0||c<0||r>=n||c>=m) return;
        if(grid[r][c]==-1) return;
        if(grid[r][c]==2){
            if(zeroes+1==cc){
                ans++;
            }
            return;
        }
        vector<int> dir={-1, 0, 1, 0, -1};
        
        for(int i=0; i<4; i++){ 
            grid[r][c]=-1;    
            helper(grid, r+dir[i], c+dir[i+1], zeroes,cc+1, ans, n, m);    
            grid[r][c]=0;
        }
        
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int zeroes=0;
        int r=0, c=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    r=i, c=j;
                }
                if(grid[i][j]==0) zeroes++;
            }
        }
        int ans=0;
        helper(grid, r, c, zeroes,0, ans, n, m);
        return ans;
    }
};