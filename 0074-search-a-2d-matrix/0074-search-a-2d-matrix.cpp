class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return 0;

        int n = matrix.size(), m = matrix[0].size();

        int st = 0, end = n * m - 1;
        while (st <= end) {
            int mid = (st + end) / 2;
            
            if (matrix[mid/m][mid%m] == target)
                return 1;
            else if (matrix[mid/m][mid%m]> target)
                end = mid - 1;
            else
                st = mid + 1;
        }
        return 0;
    }
};