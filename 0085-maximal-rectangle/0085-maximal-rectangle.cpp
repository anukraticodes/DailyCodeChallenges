class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mat[i][j]=matrix[i][j]-'0';
            }
        }
        for(int i=0; i<mat.size(); i++){
            for(int j=1; j<mat[0].size(); j++){
                if(mat[i][j]==1) mat[i][j]+=mat[i][j-1];
            }
        }
        int ans=0;
        for(int j=0 ; j<m; j++){
            for(int i=0; i<n; i++){
                int width=mat[i][j];
                if(width==0) continue;

                int curr=width;
                for(int k=i; k<n; k++){
                    if(mat[k][j]==0) break;
                    curr=min(curr, mat[k][j]);
                    ans=max(ans, curr*(k-i+1));
                }
            }
        }
        return ans;
    }
};