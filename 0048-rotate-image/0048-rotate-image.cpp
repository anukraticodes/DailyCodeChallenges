class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(i!=j){
                    swap(m[i][j],m[j][i]);
                }
            }
        }
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n;j++){
                swap(m[j][i], m[j][n-i-1]);
            }
        }
    }
};