class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n=nums.size();
        vector<int> ans(n,-1);
        vector<long long> ps(nums.size()+1, 0);
        long long div=(2*k)+1;
        for(int i=1; i<=nums.size(); i++) ps[i]=ps[i-1]+(long long)nums[i-1];
        for(int i=k; i<n-k; i++){
            long long sum=ps[i+k+1]-ps[i-k];
            ans[i]=sum/div;
        }
        return ans;
    }
};