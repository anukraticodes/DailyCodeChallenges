class Solution {
public:

    bool inRectangle(int i, int j, int k, vector<vector<int>>& p){
        int x1=p[i][0], x2=p[j][0], x3=p[k][0];
        int y1=p[i][1], y2=p[j][1], y3=p[k][1];
        if(x3>=min(x1, x2) && x3<=max(x1, x2) && y3>= min(y1, y2) && y3<=max(y1, y2)) return 1;      
        return 0;
    }

    bool upperLeft(int i, int j, vector<vector<int>>& p){
        int x1=p[i][0], x2=p[j][0];
        int y1=p[i][1], y2=p[j][1];
        if(x1<=x2 && y1>=y2) return 1;
        if(x2<=x1 && y2>=y1) return 1;
        return 0;
    }

    int numberOfPairs(vector<vector<int>>& p) {
        int cnt=0;
        sort(p.begin(), p.end());
        for(int i=0; i<p.size(); i++){
            for(int j=i+1; j<p.size(); j++){
                if(upperLeft(i, j, p)){
                    cnt++;
                }
                else continue;
                for(int k=0; k<p.size(); k++){
                  if(k!=i && k!=j){
                    if(inRectangle(i, j, k, p)){
                        cnt--;
                        break;
                    }
                  }
                }
            }
        }
        return cnt;
    }
};