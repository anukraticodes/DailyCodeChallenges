class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<2) return points.size();
        int ans=2;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int cnt=2;
                for(int k=j+1; k<points.size(); k++){
                    long long a=(points[k][1]-points[i][1])*(points[j][0]-points[i][0]);
                    long long b=(points[k][0]-points[i][0])*(points[j][1]-points[i][1]);
                    if(a==b) cnt++;
                }
                ans=max(ans, cnt);
            }
        }
        return ans;
    }
};