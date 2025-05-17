class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int cnt=1, ans=1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]) continue;
            if(nums[i+1]-nums[i]==1) cnt++;
            else{
                ans=max(ans, cnt);
                cnt=1;
            }
        }
        ans=max(ans, cnt);
        return ans;
    }
};