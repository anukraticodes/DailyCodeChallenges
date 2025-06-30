class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<long, int, int>, vector<tuple<long, int, int>>, greater<tuple<long, int, int>>> pq;
        for(auto it:points){
            int x=it[0], y=it[1];
            long dist=(x*x)+(y*y);
            pq.push({dist, x, y});
        }
        vector<vector<int>> ans;
        while(k--){
            auto [dist, x, y]=pq.top();
            pq.pop();
            ans.push_back({x, y});
        }
        return ans;
    }
};