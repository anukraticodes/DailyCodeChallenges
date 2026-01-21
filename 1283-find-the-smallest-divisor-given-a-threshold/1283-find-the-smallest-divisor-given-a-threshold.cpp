class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        long long sum=accumulate(nums.begin(), nums.end(), 0LL);
        int l=1, r=*max_element(nums.begin(), nums.end());
        while(l<r){
            int mid=(l+r)/2;
            long long val=0;
            for(auto it:nums){
                val+=(it+mid-1)/mid;
            }
            if(val<=t) r=mid;
            else l=mid+1;
        }
        return l;
    }
};