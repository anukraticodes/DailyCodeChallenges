class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        int l=0, r=m-1;
        while(l<=r){
            int mr=0, mc=(l+r)/2;
            for(int i=0; i<n; i++){
                mr=mat[i][mc]>=mat[mr][mc]?i:mr;
            }

            bool lb= mc-1>0 && mat[mr][mc]<mat[mr][mc-1];
            bool rb= mc+1<m && mat[mr][mc]<mat[mr][mc+1];
            if(!lb &&!rb) return vector<int>{mr, mc};
            else if(lb)r=mc-1;
            else l=mc+1;
        }
        return vector<int>{-1, -1};

    }
};