class Solution {
    using p= tuple<int, int, int>;
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int m=h.size(), n=h[0].size();
        priority_queue<p, vector<p>, greater<p>> q;

        vector<vector<int>> diff(m, vector<int>(n, INT_MAX));
        diff[0][0]=0;
        q.push({0,0,0});
        int drc[5]={-1, 0, 1, 0, -1};

        while(!q.empty()){
            auto [eff, i, j]= q.top();
            q.pop();
            if(eff>diff[i][j]) continue;

            for(int k=0; k<4; k++){
                int x=i+drc[k];
                int y=j+drc[k+1];
                if(x>=0 && y>=0 && x<m && y<n){
                    int neweff=max(abs(h[x][y]-h[i][j]), eff);
                    if(neweff < diff[x][y]){
                        diff[x][y]=neweff;
                        q.push({neweff,x, y});
                    }
                }
            }
        }
return diff[m-1][n-1];
    }
};