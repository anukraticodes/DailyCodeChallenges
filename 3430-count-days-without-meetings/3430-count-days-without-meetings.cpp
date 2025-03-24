class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int cnt=0;
        vector<vector<int>> final;
        sort(meetings.begin(), meetings.end(), [&](const vector<int> a, const vector<int> b){
            return a[0]<b[0];
        });
        int start=meetings[0][0], end=meetings[0][1];
        for(int i=1; i<meetings.size(); i++){
            int a=meetings[i][0], b=meetings[i][1];
            // int c=meetings[i+1][0], d=meetings[i+1][1];
            if(a<=end){
                end=max(end, b);
            }
            else{
                final.push_back({start, end});
                start=a, end=b;
            }
        }
        final.push_back({start, end});
        for (const auto& interval : final) {
        cnt += interval[1] - interval[0] + 1;
    }
        return days-cnt;
    }
};