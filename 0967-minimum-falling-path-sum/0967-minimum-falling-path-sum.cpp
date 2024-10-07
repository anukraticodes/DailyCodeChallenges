class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int res = INT_MAX;
        for(int i=1; i<matrix.size(); i++) {
            for(int x=0; x<matrix[i].size(); x++) {
                int prev = matrix[i-1][x];
                if(x>0) prev = min(prev, matrix[i-1][x-1]);
                if(x<matrix[i].size()-1) prev = min(prev, matrix[i-1][x+1]);
                matrix[i][x] += prev;
            }
        }
        vector<int> arr;
        arr.swap(matrix[matrix.size()-1]); 
        sort(arr.begin(), arr.end());
        return arr[0];
        
    }
};