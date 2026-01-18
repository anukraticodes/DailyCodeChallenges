class Solution {
public:

    bool ismagic(int i, int j, int a, int b, vector<vector<int>>& ps, vector<vector<int>>& grid){
        //for row
        int val=ps[i][b]-ps[i][j-1]-ps[i-1][b]+ps[i-1][j-1];
        for(int ind=i+1; ind<=a; ind++){
            if(ps[ind][b]-ps[ind][j-1]-ps[ind-1][b]+ps[ind-1][j-1]!=val) return 0;
        }
        //for col
        for(int ind=j; ind<=b; ind++){
            if(ps[a][ind]-ps[i-1][ind]-ps[a][ind-1]+ps[i-1][ind-1]!=val) return 0;
        }
        //for diagonal
        int sum1=0, sum2=0;
        int ind=i, ind2=j;
        while(ind<=a && ind2<=b){
            sum1+=grid[ind-1][ind2-1];
            ind++, ind2++;
        }
        if(sum1!=val) return 0;
        sum2=0;
        ind=i, ind2=b;
        while(ind<=a && ind2>=j){
            sum2+=grid[ind-1][ind2-1];
            ind++, ind2--;
        }
        if(sum2!=val) return 0;
        return 1;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ans=1;
        vector<vector<int>> ps(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=m; i++){
            ps[0][i]=ps[0][i-1]+grid[0][i-1];
        }
        for(int i=1; i<=n; i++){
            ps[i][0]=ps[i-1][0]+grid[i-1][0];
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+grid[i-1][j-1];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int a=i, b=j;
                while(a<n && b<m){
                    if(ismagic(i+1,j+1,a+1,b+1,ps,grid)){
                        ans=max(ans, (a-i+1));
                    }
                    a++,b++;
                }
            }
        }
        return ans;
    }
};