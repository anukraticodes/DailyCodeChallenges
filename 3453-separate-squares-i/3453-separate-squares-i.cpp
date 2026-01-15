class Solution {
public:

double area(double y, vector<vector<int>>& squares) {
    double area = 0;
    for (auto &s : squares) {
        double bottom = s[1];
        double top = s[1] + s[2];
        double side = s[2];

        if (y <= bottom) continue;
        else if (y >= top) area += side * side;
        else area += (y - bottom) * side;
    }
    return area;
}
    double separateSquares(vector<vector<int>>& squares) {
        double total=0, ymin=1e8, ymax=1e-8;
        for(auto it:squares){
           total+=1.0*it[2]*it[2];
           ymin=min(ymin, (double)it[1]);
           ymax=max(ymax, (double)it[1]+it[2]);
        }

        double target=total/2.0;

        for(int i=0; i<100; i++){
            double mid=(ymin+ymax)/2;
            if(area(mid,squares)<target) ymin=mid;
            else ymax=mid;
        }
        return ymin;

    }
};