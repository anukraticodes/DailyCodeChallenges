class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum=0,ans=0; int n=nums.size();
        
        map<int, int> mp;
        mp[0]=1;
        for(int i=0; i<n; i++){
            if(nums[i]%2!=0) nums[i]=1;
            else nums[i]=0;
        }
      
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};