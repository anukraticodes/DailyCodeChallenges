class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        
        int target=0;
        for(int i=0; i<n; i++){
            target+=nums[i];
        }
        if(target%2!=0) return false;
        int sum=target/2;
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        return helper(nums, dp, sum);
        }

        bool helper(vector<int>& nums, vector<vector<bool>>& dp, int sum){
            int n=nums.size();
            for(int i=0; i<n; i++){
                dp[i][0]=true;
            }
            if(nums[0]<=sum) dp[0][nums[0]]=true;
            for(int ind=1; ind<n; ind++){
                for(int k=1; k<=sum; k++){
                    bool nottaken=dp[ind-1][k];
                    bool taken =0;
                    if(nums[ind]<=k) taken=dp[ind-1][k-nums[ind]];
                    dp[ind][k]=taken||nottaken;
                }
            }
            return dp[n-1][sum];

        }
    
};