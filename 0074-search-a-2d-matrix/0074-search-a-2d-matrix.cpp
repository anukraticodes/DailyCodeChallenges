class Solution {
public:
    int bs(vector<int>& v, int target){
        int l=0, r=v.size();
        while(l<r){
            int mid=(l+r)/2;
            if(v[mid]>=target) r=mid;
            else l=mid+1;
        }
        return l;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> col;
        for(int i=0; i<matrix.size(); i++) col.push_back(matrix[i][0]);
        int ind=bs(col, target);
     
        if(ind<matrix.size() && matrix[ind][0]==target) return 1;
        if(ind==0) return 0;
        col.clear();
        for(int i=0; i<matrix[0].size(); i++) col.push_back(matrix[ind-1][i]);
        int ind2=bs(col, target);
        return (ind2<matrix[0].size() && matrix[ind-1][ind2]==target)?1:0;
    }
};