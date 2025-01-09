class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int r=m.size(), c=m[0].size();
        int x=0, y=0, dx=1, dy=0;
        vector<int> ans;
        for(int i=0; i<r*c; i++){
            ans.push_back(m[y][x]);
            m[y][x]=-101;
            if(!(0<=x+dx&&x+dx<c&&0<=y+dy&&y+dy<r)|| m[y+dy][x+dx]==-101){
                int temp=dx;
                dx=-dy;
                dy=temp;
            }
            x+=dx;
            y+=dy;
        }
        return ans;
    }
};