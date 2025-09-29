class Solution {
public:

   int helper(int i, int j, unordered_map<int, int>& dp, vector<int>& v){
    int n=v.size();
    if(i+2>j) return 0;
    if(i+j==2){
        return v[i]*v[j]*v[i+1];
    }
    int key=i*n+j;
    if(!dp.count(key)){
        int minans=INT_MAX;
        for(int k=i+1; k<j; k++){
            minans=min(minans, v[i]*v[j]*v[k]+helper(i, k, dp, v)+helper(k,j, dp, v));
        }
        dp[key]=minans;
    }
    return dp[key];
   }

    int minScoreTriangulation(vector<int>& v) {
        unordered_map<int, int> dp;
        int n=v.size();
        return helper(0, n-1, dp, v);
    }
};