class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(weights.size()<k) return -1;
        int n=weights.size();
        vector<int> v(n-1, 0);
        for(int i=0; i<n-1; i++) v[i]+=weights[i]+weights[i+1];
        sort(v.begin(), v.end());
        long long res=0;
        for(int i=0; i<k-1; i++) res+=v[n-2-i]-v[i];
        return res;
    }
};