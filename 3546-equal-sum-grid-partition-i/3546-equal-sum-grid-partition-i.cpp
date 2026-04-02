class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        long long row=0;
        long long ts=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ts+=grid[i][j];
            }
        }

        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
               row+=grid[i][j];
            }
            if(row == ts-row) return true;
        }

        long long col=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                col+=grid[i][j];
            }
            if(col == ts-col) return 1;
        }
        return 0;
    }
};