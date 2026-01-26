class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l=0, r=mat[0].size()-1;
        while(l<=r){
            int mr=0, mc=(l+r)/2;
            for(int i=0; i<mat.size(); i++){
                mr=mat[i][mc]>=mat[mr][mc]?i:mr;
            }

        bool leftisbig=mc-1>=l && mat[mr][mc-1]>mat[mr][mc];
        bool rightisbig=mc+1<=r && mat[mr][mc+1]>mat[mr][mc];
        if(!leftisbig && !rightisbig) return vector<int>{mr, mc};
        else if(rightisbig) l=mc+1;
        else r=mc-1;
        }
        return vector<int>{-1,-1};
    }
};