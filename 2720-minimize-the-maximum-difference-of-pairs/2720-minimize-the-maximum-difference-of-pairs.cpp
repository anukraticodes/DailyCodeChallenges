class Solution {
public:

    int helper(vector<int>& nums, int t){
        int ind=0, cnt=0;
        while(ind<nums.size()-1){
            if(nums[ind+1]-nums[ind]<=t){
                cnt++;
                ind++;
            }
            ind++;
        }
        return cnt;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int l=0, r=nums[n-1]-nums[0];
        while(l<r){
            int mid=l+(r-l)/2;
            if(helper(nums, mid)>=p) r=mid;
            else l=mid+1;
        }
        return l;
    }
};