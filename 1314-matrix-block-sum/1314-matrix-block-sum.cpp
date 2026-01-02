class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> pref(n, vector<int>(m, 0));
        pref[0][0]=mat[0][0];
        for(int i=1; i<n; i++){
            pref[i][0]+=pref[i-1][0]+mat[i][0];
        }
        for(int i=1; i<m; i++){
            pref[0][i]+=pref[0][i-1]+mat[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+mat[i][j];
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int r1=max(0, i-k), c1=max(0, j-k);
                int r2=min(n-1, i+k), c2=min(m-1, j+k);
                int val=0;
                val+=pref[r2][c2]-(r1>0?pref[r1-1][c2]:0)-(c1>0?pref[r2][c1-1]:0)+(r1>0&&c1>0?pref[r1-1][c1-1]:0);
                ans[i][j]=val;
            }
        }
return ans;

    }
};