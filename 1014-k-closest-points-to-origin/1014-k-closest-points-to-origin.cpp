class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<long, int, int>> pq;
        for(auto it:points){
            int x=it[0], y=it[1];
            long dist=((x*x)+(y*y));
            pq.push({dist, x, y});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto [dist, x, y]=pq.top();
            ans.push_back({x, y});
            pq.pop();
        }
        return ans;
    }
};