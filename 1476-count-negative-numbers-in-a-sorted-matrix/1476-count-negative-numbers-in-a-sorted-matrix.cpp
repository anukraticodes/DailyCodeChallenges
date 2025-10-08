class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            int cnt=helper(grid[i], 0);
            ans+=m-cnt;
        }
        return ans;
    }

    int helper(vector<int>& nums, int target){
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>=target) l=mid+1;
            else if(nums[mid]<target) r=mid-1;
        }
        return l;
    }
};