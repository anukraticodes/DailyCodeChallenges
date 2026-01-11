class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n=mat.size(), m=mat[0].size();
        int ans=0;
        vector<int> h(201,0), st(201,-1);
        for(int i=0; i<n; i++){
            int top=0;
            for(int j=0; j<=m; j++){
               h[j]=(j==m || mat[i][j]=='0')?0:h[j]+1;

               while(top>0 && (j==m || h[j]<h[st[top]])){
                int m=st[top--];
                int w=j-st[top]-1;
                int a=h[m]*w;
                ans=max(ans, a);
               }
               st[++top]=j;
            }
        }
        return ans;
    }
};