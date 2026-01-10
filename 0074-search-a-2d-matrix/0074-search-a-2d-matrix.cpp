class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int st=0, end=n-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(matrix[mid][0]>target) end=mid-1;
            else if(matrix[mid][0]<target) st=mid+1;
            else return 1;
        }
        int row=st-1;
        if (row < 0) return false;
        st=0, end=m-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(matrix[row][mid]>target) end=mid-1;
            else if(matrix[row][mid]<target) st=mid+1;
            else return 1;
        }
        return 0;
    }
};