class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int cnt = 0;
        int n=events.size();
        sort(events.begin(), events.end());
        int maxDay = 0;
        for (int i = 0; i < events.size(); i++) {
            maxDay = max(maxDay, events[i][1]);
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0, j=0; i<=maxDay; i++){
            while(j<n && events[j][0]<=i){
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty() && pq.top()<i) pq.pop();
            if(!pq.empty()){
                pq.pop();
                cnt++;
            }
        }
        return cnt;
    }
};