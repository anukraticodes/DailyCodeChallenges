class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int l=0, r=m*n-1;
        while(l<=r){
            int mid=(l+r)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target) return 1;
            if(matrix[row][col]>target) r=mid-1;
            else l=mid+1;
        }
        
        return 0;
    }
};