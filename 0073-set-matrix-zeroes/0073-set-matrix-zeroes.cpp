class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        set<int> r,c;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(auto ele: r){
                matrix[ele][i]=0;
            }
        }

        for(int i=0; i<m; i++){
            for(auto ele: c){
                matrix[i][ele]=0;
            }
        }

    }
};