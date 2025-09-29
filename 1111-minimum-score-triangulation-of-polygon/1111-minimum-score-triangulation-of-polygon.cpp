class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int n=v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 2; j < n; j++) {           
            for (int i = j - 2; i >= 0; i--) {
                if(j-i+1==3){
                    dp[i][j]=v[i]*v[j]*v[i+1];
                }
                else{
                   int globalprod=INT_MAX;
                  
                for(int k=i+1; k<j; k++){
                     int sum=dp[i][k]+dp[k][j];
                    int prod=v[i]*v[j]*v[k];
                    globalprod=min(prod+sum, globalprod);
                }
                dp[i][j]=globalprod;
                }
            }
        }
        return dp[0][n-1];
    }
};