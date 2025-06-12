class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int diff=nums[i]-nums[(i+1)%nums.size()];
            diff=abs(diff);
            ans=max(ans, diff);
        }
        return ans;
    }
};