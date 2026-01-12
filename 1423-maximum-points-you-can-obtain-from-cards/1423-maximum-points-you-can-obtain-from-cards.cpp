class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int currs=0,i=0;
        for(i=0; i<k; i++) currs+=cp[i];
        i--;
        int r=cp.size()-1;
        int ans=currs;
        while(i>=0){
          currs-=cp[i--];
          currs+=cp[r--];
          ans=max(ans, currs); 
        }
        // ans=max(ans, currs);
        return ans;
    }
};