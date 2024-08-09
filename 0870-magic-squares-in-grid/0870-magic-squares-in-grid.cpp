class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n*m<9) return 0;
        int cnt=0;
        for(int i=0; i<=n-3; i++){
            for(int j=0; j<=m-3; j++){
                if(helper(i, j, grid)) cnt++;
            }
        }
        return cnt;
    }

    bool helper(int i, int j, vector<vector<int>>& grid){
        vector<int> count(10, 0);
        for(int x=0; x<3; x++){
            for(int y=0; y<3; y++){
                int num=grid[i+x][j+y];
                if(num<1 || num>9 || count[num]>0) return false;
                count[num]++;
            }
        }

        int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2];

        for(int x=0; x<3; x++){
            if(sum!=(grid[i+x][j]+grid[i+x][j+1]+grid[i+x][j+2])) return false;
        }

        for(int x=0; x<3; x++){
            if(sum!=(grid[i][j+x]+ grid[i+1][j+x]+ grid[i+2][j+x])) return false;
        }
         
        if(sum != (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2])) return false;
        if(sum != (grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2])) return false;

        return true;

    }
};