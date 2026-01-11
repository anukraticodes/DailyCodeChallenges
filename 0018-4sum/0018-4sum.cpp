class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<nums.size(); j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                long long t=(long long)target-nums[i]-nums[j];
                int l=j+1, r=nums.size()-1;
                while(l<r){
                    long long val=nums[l]+nums[r];
                    if(val>t) r--;
                    else if(val<t) l++;
                    else {ans.push_back({nums[i],nums[j],nums[l],nums[r]}); 
                    int vall=nums[l], valr=nums[r];
                    while(l<r && nums[l]==vall)l++;
                    while(l<r && nums[r]==valr)r--;
                    }
                }
            }
        }
        return ans;
    }
};