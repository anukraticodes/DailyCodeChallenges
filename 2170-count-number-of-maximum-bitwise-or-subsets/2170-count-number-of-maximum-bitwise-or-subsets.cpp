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
       
        int cnt=0;
        
        helper(nums, 0, 0, dp[n-1], cnt);
        return cnt;        
    }

    void helper(const vector<int>& nums, int i, int curr, int maxi, int& cnt){
        if(curr==maxi) cnt++;

        for(int j=i; j<nums.size(); j++){
            helper(nums, j+1, curr|nums[j], maxi, cnt);
        }      
    }
};