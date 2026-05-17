class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int st=bs(nums, target, 1);
        if(st==n || nums[st]!=target) return {-1, -1};
        int end=bs(nums, target, 0);
        return {st, end-1};
    }

    int bs(vector<int>& nums, int target, bool flag){
        int l=0, r=nums.size();
        while(l<r){
            int mid=(l+r)/2;
           
            if(nums[mid]>target) r=mid;
            
            else if(flag==1 && nums[mid]==target){
              r=mid;
            }
            else l=mid+1;
        }
        return l;
    }
};