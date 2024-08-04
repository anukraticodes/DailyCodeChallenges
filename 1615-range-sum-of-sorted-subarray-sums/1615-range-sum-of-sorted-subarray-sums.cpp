class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum;
        for(int i=0; i<n; i++){
            int prefix=0;
            for(int j=i; j<n; j++){
                prefix+=nums[j];
                sum.push_back(prefix);
            }
        }
        sort(sum.begin(), sum.end());
        int ans=0;
        int MOD= 1000000007;
        for(int i=left-1; i<right; i++){
            ans=(ans+ sum[i])% MOD;
        }
        return ans;
    }
};