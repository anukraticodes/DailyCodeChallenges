class Solution {
public:
    int bs1(vector<vector<int>>& v, int target){
        int l=0, r=v.size();
        while(l<r){
            int mid=(l+r)/2;
            if(v[mid][0]>=target) r=mid;
            else l=mid+1;
        }
        return l;
    }
    int bs2(vector<vector<int>>& v, int target, int ind){
        int l=0, r=v[0].size();
        while(l<r){
            int mid=(l+r)/2;
            if(v[ind][mid]>=target) r=mid;
            else l=mid+1;
        }
        return l;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ind=bs1(matrix, target);
     
        if(ind<matrix.size() && matrix[ind][0]==target) return 1;
        if(ind==0) return 0;
        
        int ind2=bs2(matrix, target, ind-1);
        return (ind2<matrix[0].size() && matrix[ind-1][ind2]==target)?1:0;
    }
};