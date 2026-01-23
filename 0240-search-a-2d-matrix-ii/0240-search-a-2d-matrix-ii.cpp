class Solution {
public:
    int helper(vector<int>& v, int t, int thresh){
        int l=0, r=thresh+1;
        while(l<r){
            int mid=(l+r)/2;
            if(v[mid]>=t) r=mid;
            else l=mid+1;
        }
        return l;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int t) {
        int n=matrix.size(), m=matrix[0].size();
        int threshold=m-1;
       for(int i=0; i<n; i++){
            int lb=helper(matrix[i],t, threshold);
            if(lb==threshold+1) continue;

            if(matrix[i][lb]!=t){
                if(lb==0) return 0;
                threshold=lb-1;
            }
            else return true;
        }
        return 0;
    }
};