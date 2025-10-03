class Cell{
    public:
    int height, row, col;
    Cell(int h, int r, int c){
        height=h;
        row=r;
        col=c;
    }

    bool operator<(const Cell& other) const{
        return height>other.height;
    }
};

bool isValid(int r, int c, int nr, int nc){
    return r>=0 && c>=0 && r<nr && c<nc;
}


class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int drow[4]={0,0,-1,1};
        int dcol[4]={-1,1,0,0};

        int nr=heightMap.size();
        int nc=heightMap[0].size();

        vector<vector<bool>> vis(nr, vector<bool>(nc, 0));
        priority_queue<Cell> q;

        for(int i=0; i<nr; i++){
            q.push(Cell(heightMap[i][0], i, 0));
            q.push(Cell(heightMap[i][nc-1], i, nc-1));
            vis[i][0]=1;
            vis[i][nc-1]=1;
        }
        
        for(int i=0; i<nc; i++){
            q.push(Cell(heightMap[0][i], 0, i));
            q.push(Cell(heightMap[nr-1][i], nr-1, i));
            vis[0][i]=1;
            vis[nr-1][i]=1;
        }
        
        int ans=0;

        while(!q.empty()){
            Cell curr=q.top();
            q.pop();

            int cr=curr.row;
            int cc=curr.col;
            int ch=curr.height;

            for(int d=0; d<4; d++){
                int neighborr=cr+drow[d];
                int neighborc=cc+dcol[d];

                if(isValid(neighborr, neighborc, nr, nc)&&!vis[neighborr][neighborc]){
                    int neighborh=heightMap[neighborr][neighborc];
                    if(neighborh<ch) ans+=ch-neighborh;

                    q.push(Cell(max(neighborh, ch), neighborr, neighborc));
                    vis[neighborr][neighborc]=1;
                }
            }
        }
        return ans;
    }
};

