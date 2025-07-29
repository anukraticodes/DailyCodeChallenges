class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=INT_MIN;
        for(int i=0; i<p.size(); i++){
            int curr=p[i];
            for(int j=i+1; j<p.size(); j++){
                if(p[j]>p[i]){
                    curr=max(curr, p[j]);
                }
            }
            ans=max(ans, curr-p[i]);
        }
        return ans;
    }
};