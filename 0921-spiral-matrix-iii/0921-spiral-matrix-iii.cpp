class Solution {
public:

bool inside(int i, int j, int rows, int cols){
    return (i>=0 && j>=0 && i<rows && j<cols);
}
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rS, int cS) {
        vector<vector<int>> ans(rows*cols);
        ans[0]={{rS,cS}};
        int layer=max({rows-rS, cols-cS, rS+1, cS+1})+1;
        int i=rS, j=cS, k=1;
        
        for(int m=1; m<layer; m++){
            int di=0, dj=1, step=2*m-1;
            for(int a=0; a<step; a++){
                i+=di, j+=dj;
                if(inside(i, j, rows, cols)) ans[k++]={{i,j}};
            }
            di=1, dj=0;
            for(int a=0; a<step; a++){
                i+=di, j+=dj;
                if(inside( i, j, rows, cols)) ans[k++]={{i,j}};
            }
            di=0, dj=-1;
            step++;
            for(int a=0; a<step; a++){
                i+=di, j+=dj;
                if(inside( i, j, rows, cols)) ans[k++]={{i,j}};
            }
            di=-1, dj=0;
            for(int a=0; a<step; a++){
                i+=di, j+=dj;
                if(inside( i, j, rows, cols)) ans[k++]={{i,j}};
            }

        }
        return ans;
    }
};