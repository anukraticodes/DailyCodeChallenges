class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0; i<points.size()-1; i++){
          int x1=points[i][0], y1=points[i][1];
          int x2=points[i+1][0], y2=points[i+1][1];
          while(x1<x2 && y1<y2){
            ans++;
            x1++,y1++;
          }
          while(x1>x2&&y1<y2){
            ans++;
            x1--, y1++;
          }
          while(x1<x2&&y1>y2){
            ans++;
            x1++, y1--;
          }
          while(x1>x2 && y1>y2){
            ans++;
            x1--, y1--;
          }
          ans+=(x1==x2)?abs(y2-y1):abs(x2-x1);
          cout<<ans<<" ";
        }
        return ans;
    }
};