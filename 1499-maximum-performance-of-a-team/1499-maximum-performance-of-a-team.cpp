class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
       vector<pair<int, int>> v;
       for(int i=0; i<n; i++){
        v.push_back({e[i], s[i]});
       } 
       sort(v.rbegin(), v.rend());
     
       long long sum=0,ans=0;
       priority_queue<int, vector<int>, greater<int>> pq;
       for(auto& [a, b]:v){
        pq.push(b);
        sum+=b;
        if(pq.size()>k){
            sum-=pq.top();
            pq.pop();
        }
        ans=max(ans, sum*a);
       }
       return ans % (int)(1e9+7);
    }
};