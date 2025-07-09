class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& s, vector<int>& e) {
        int n=s.size(), ans=0, dur=0;
        for(int i=0; i<n; i++){
            dur+=e[i]-s[i];
            int l=i<=k-1?0:e[i-k];
            int r=i==n-1?eventTime:s[i+1];
            ans=max(ans, r-l-dur);
            if(i>=k-1){
                dur-=e[i-k+1]-s[i-k+1];
            }
        }
        return ans;
    }
};