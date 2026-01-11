class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        matrix[i][j]=mat[i][j]-'0';

        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j]==1) matrix[i][j]+=matrix[i][j-1];
            }
        }
        int ans=0;
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                int w=matrix[i][j];
                if(w==0) continue;

                int currw=w;
                for(int k=i; k<n && matrix[k][j]>0; k++){
                    currw=min(currw, matrix[k][j]);
                    int h=k-i+1;
                    ans=max(ans, currw*h);
                }

                currw=w;
                for (int k = i; k >= 0 && matrix[k][j] > 0; k--) {
                    currw = min(currw, matrix[k][j]);
                    int h= i - k + 1;
                    ans = max(ans, currw * h);
                }
            }
        }
        return ans;
    }
};