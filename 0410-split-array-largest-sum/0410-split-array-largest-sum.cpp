class Solution {
public:
    bool helper(vector<int>& nums, int k, int mid){
        int cnt=1, total=0;
        for(auto num:nums){
            total+=num;
            if(total>mid){
                total=num;
                cnt++;
                if(cnt>k) return 0;
            }
            
        }
        return 1;
    }

    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(), nums.end());
        int r=accumulate(nums.begin(), nums.end(), 0);
        while(l<r){
            int mid=l+(r-l)/2;
            if(helper(nums, k, mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};