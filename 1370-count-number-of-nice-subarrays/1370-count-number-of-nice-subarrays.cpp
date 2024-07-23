class Solution {
public:
    int func(vector<int>& nums, int k) {
        int l=0, r=0, cnt=0;
        int num=0;
        while(r<nums.size()){
            if(nums[r]&1) cnt++;
            while(cnt>k){
               if(nums[l]&1) cnt--;
               l++;
            }
            num+=(r-l+1);
            r++;
        }
        return num;
    }
    int numberOfSubarrays(vector<int>& nums, int k){
        return func(nums,k)-func(nums,k-1);
    }
};