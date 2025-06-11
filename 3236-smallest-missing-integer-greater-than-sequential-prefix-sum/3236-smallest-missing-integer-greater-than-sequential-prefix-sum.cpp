class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                ans += nums[i];
            } else {
                break;
            }
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<ans) continue;
            else if(nums[i]==ans) ans++;
            else if(nums[i]>ans) break;
        }
        return ans;

    }
};