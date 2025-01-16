class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       return func(nums,k)-func(nums,k-1);
    }

    int func(vector<int>& nums, int k){
         for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        int r=0, l=0, sum=0, cnt=0;
        for(r=0; r<nums.size(); r++){
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            cnt+=r-l+1;
        }
        return cnt;
    }
};