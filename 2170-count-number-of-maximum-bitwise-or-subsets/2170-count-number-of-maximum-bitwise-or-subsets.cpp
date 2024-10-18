class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);
        dp[0]=nums[0];
        for(int i=1; i<n; i++){
            int take=(nums[i]|dp[i-1]);
            dp[i]=max(take, dp[i-1]);
        }
        int maxi=dp[n-1];
        int cnt=0;
        vector<vector<int>> result;
        vector<int> v;
        helper(0,v, nums, n, result);
        for(int i=0; i<result.size(); i++){
            int val=0;
            for(int j=0; j<result[i].size(); j++){
                val|=result[i][j];
            }
            if(val==maxi) cnt++;
        }
        return cnt;        
    }

    void helper(int i,vector<int>& v, vector<int>& nums, int n, vector<vector<int>>& result){
        if(i==n){
            result.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        helper(i+1, v, nums, n, result);
        v.pop_back();
        helper(i+1,v,nums,n, result);        
    }
};