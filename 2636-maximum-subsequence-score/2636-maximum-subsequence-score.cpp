class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++) v[i]={nums2[i], nums1[i]};
        sort(v.rbegin(), v.rend());
        long long sum=0, ans=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& [a, b]:v){
            pq.push(b);
            sum+=b;
           if(pq.size()>k){
            sum-=pq.top();
            pq.pop();
           }
           if(pq.size()==k) ans=max(ans, sum*a);
        }
        return ans;
    }
};