class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n=cp.size();
        vector<int> ps(n+1,0);
      
        for(int i=1; i<=cp.size(); i++){
            ps[i]=ps[i-1]+cp[i-1];
        }
        int l=0, r=n-k-1;
        int tot=accumulate(cp.begin(), cp.end(),0);
        int ans=INT_MIN;
        while(r<n){
            ans=max(ans,tot-(ps[r+1]-ps[l]));
            l++, r++;
        }
        return ans;
    }
};