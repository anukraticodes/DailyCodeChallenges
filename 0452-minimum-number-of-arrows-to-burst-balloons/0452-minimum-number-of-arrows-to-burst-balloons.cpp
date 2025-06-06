class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans=0;
        int prev_end=points[0][1];
        for(int i=1; i<points.size(); i++){
           if(points[i][0]<=prev_end){
            prev_end=min(prev_end, points[i][1]);
           }
           else{
            ans++;
            prev_end=points[i][1];
           }
        }
        return ans+1;
    }
};