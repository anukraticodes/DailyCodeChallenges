class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int st=lb(nums, target);
        if(st==n || nums[st]!=target) return {-1, -1};
        int end=up(nums, target);
        return {st, end-1};
    }

    int lb(vector<int>& nums, int target){
        int l=0, r=nums.size();
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        return l;
    }

    int up(vector<int>& nums, int target){
        int l=0, r=nums.size();
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>target) r=mid;
            else l=mid+1;
        }
        return l;
    }
};