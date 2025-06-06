class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newi) {
        intervals.push_back(newi);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;
        v.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(v.back()[1]>=intervals[i][0])
            v.back()[1]=max(v.back()[1], intervals[i][1]);
            else{
                v.push_back(intervals[i]);
            }
        }
        return v;
    }
};