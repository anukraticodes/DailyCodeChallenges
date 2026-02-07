class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<int> h(201,0), st(201, -1);
        int ans=0;
        for(int i=0; i<n; i++){
            int top=0;
            for(int j=0; j<=m; j++){
                h[j]=(j==m || matrix[i][j]=='0')?0:h[j]+1;
                while(top>0 && (j==m || h[st[top]]>h[j])){
                    int height=st[top--];
                    int w=j-st[top]-1;
                    ans=max(ans, h[height]*w);
                }
                st[++top]=j;
            }
        }
        return ans;
    }
};