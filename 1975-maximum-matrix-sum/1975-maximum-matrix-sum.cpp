class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& m) {
        long long ans=0;
       int cntNeg=0;
         int lv=INT_MAX;
        for(int i=0; i<m.size(); i++){
            for(int j=0; j<m[0].size(); j++){
                if(m[i][j]<0) cntNeg++;
                ans+=abs(m[i][j]);
                lv=min(lv,abs(m[i][j]));
            }
        }
        if(cntNeg%2!=0) ans-=(2*lv);
        return ans;
    }
};