class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int stInd=intervals[0][0];
        int prev=intervals[0][1];
        vector<vector<int>> ans;
        for(int i=1; i<intervals.size(); i++){
            int currstart=intervals[i][0];
            if(currstart<=prev) prev=max(prev,intervals[i][1]);
            else{
                ans.push_back({stInd, prev});
                stInd=currstart;
                prev=max(prev,intervals[i][1]);
            }
        }
        ans.push_back({stInd, prev});
        return ans;
    }
};