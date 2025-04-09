class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0, r=k-1;
        double sum=(accumulate(nums.begin(), nums.begin()+k, 0.0));
        double ans=sum/k;
        while(r<nums.size()-1){
            sum-=nums[l++];
            sum+=nums[++r];
            ans=max(ans, sum/k);
        }
        return ans;
    }
};