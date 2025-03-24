class Solution {
public:

bool helper(vector<int>& nums, int t, int mid){
    long long total=0;
    for(int i=0; i<nums.size(); i++){
        total+=(nums[i]+mid-1LL)/mid;
        if(total>t) return 0;
    }
    return 1;
}
    int smallestDivisor(vector<int>& nums, int t) {
        // int sum=accumulate(nums.begin(), nums.end(), 0);
        int l=1, r=*max_element(nums.begin(), nums.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            if(helper(nums, t, mid)){
                r=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};