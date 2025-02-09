class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        for(long long i=0; i<n; i++){
            nums[i]=nums[i]-i;
        }
        sort(nums.begin(), nums.end());
        long long cnt=0; long long ans=0;
        for(long long i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]) cnt++;
            else{
                ans+=(cnt*(cnt+1))/2;
                cnt=0;
            }
        }
        ans+=(cnt*(cnt+1))/2;
        return (n*(n-1))/2-ans;
    }
};