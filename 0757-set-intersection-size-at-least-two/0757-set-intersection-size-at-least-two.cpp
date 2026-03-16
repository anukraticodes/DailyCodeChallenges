class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto& a, auto& b){
            if(a[1]==b[1]) return a[0]>b[0];
            return a[1]<b[1];
        });

        vector<int> v;
        int curr1=intervals[0][1], curr2=intervals[0][1]-1;
        for(int i=1; i<intervals.size(); i++){
             if(curr2>=intervals[i][0]) continue;
             if(curr1>=intervals[i][0]){
                curr2=curr1;
                curr1=intervals[i][1];
                v.push_back(curr1);
             }
             else{
                curr1=intervals[i][1];
                curr2=intervals[i][1]-1;
                v.push_back(curr2); v.push_back(curr1);
             }
        }
        return v.size()+2;
    }
};