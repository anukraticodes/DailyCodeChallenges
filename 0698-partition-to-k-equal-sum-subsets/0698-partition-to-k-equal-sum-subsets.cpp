class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0) return 0;
        int target=sum/k;
        // sort(nums.rbegin(), nums.rend());
        vector<bool> vis(n, 0);
        return helper(nums, vis, 0, k, 0, target);
    }

    int helper(vector<int>& nums, vector<bool>& vis, int start, int k, int currsum, int target){
        if(k==1) return 1;
        if(currsum==target) return helper(nums, vis, 0, k-1, 0, target);
        for(int i=start; i<nums.size();i++){
            if(vis[i]||currsum+nums[i]>target) continue;
            vis[i]=1;
            if(helper(nums, vis, i+1, k, currsum+nums[i], target)) return 1;
            vis[i]=0;
            if(currsum==0) break;
        }
        return 0;
    }
};