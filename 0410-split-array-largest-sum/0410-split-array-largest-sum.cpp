class Solution {
public:

    bool possible(vector<int>& nums, int k, int mid){
        int cnt=1, sum=0;
        for(int r=0; r<nums.size(); r++){
            sum+=nums[r];
            if(sum>mid){
                sum=nums[r];
                if(++cnt >k) return 0;
            }
        }
        return 1;
    }

    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(), nums.end());
        int r=accumulate(nums.begin(), nums.end(), 0);
        while(l<r){
            int mid=(l+r)/2;
            if(possible(nums, k, mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};