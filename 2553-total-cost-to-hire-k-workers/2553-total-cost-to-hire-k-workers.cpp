class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1, pq2;
        int a=0;
        int j=costs.size()-1;
        long long ans=0;
        
        while(pq1.size()< c && a <= j) {
            pq1.push({costs[a], a});
            a++;
        }
        while(pq2.size() < c && j >= a){
            pq2.push({costs[j], j});
            j--;
        }
        while(k--){
        if (pq2.empty() || (!pq1.empty() && pq1.top().first <= pq2.top().first)) {
            ans += pq1.top().first;
            pq1.pop();
            if (a <= j) {
                pq1.push({costs[a], a});
                a++;
            }
        }
        else{ 
          ans += pq2.top().first;
            pq2.pop();
            if (j >= a) {
               pq2.push({costs[j], j});
                j--;
            }
        }
        }
        
        return ans;
    }
};