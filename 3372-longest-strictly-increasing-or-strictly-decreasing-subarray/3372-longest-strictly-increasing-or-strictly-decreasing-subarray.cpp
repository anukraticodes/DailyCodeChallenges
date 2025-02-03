class Solution {
public:
    int longestMonotonicSubarray(vector<int>& n) {
        if(n.size()==1) return 1;
        int cnt1=0, ans=INT_MIN; bool flag=0;
        for(int i=0; i<n.size()-1; i++){
            if(n[i]>n[i+1]){
               cnt1++;
            } 
            else cnt1=0;
            ans=max(cnt1, ans);
        }
        int cnt2=0;
        for(int i=0; i<n.size()-1; i++){
            if(n[i]<n[i+1]){
                cnt2++;
            }
            else cnt2=0;
            ans=max(ans, cnt2);
        }
        return ans+1;
    }
};