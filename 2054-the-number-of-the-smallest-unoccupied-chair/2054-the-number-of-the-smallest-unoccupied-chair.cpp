class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();

        vector<pair<int, int>> arrivals;
        for(int i=0; i<n; i++){
            arrivals.push_back({times[i][0], i});
        }
        sort(arrivals.begin(), arrivals.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<n; i++){
            pq.push(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        for(auto& arrival: arrivals){
            int a=arrival.first;
            int ind=arrival.second;

            while(!pq2.empty() && pq2.top().first<=a){
                pq.push(pq2.top().second);
                pq2.pop();
            }

            int chair=pq.top();
            pq.pop();

            if(ind==targetFriend) return chair;

            pq2.push({times[ind][1], chair});
        }
        return -1;
    }
};