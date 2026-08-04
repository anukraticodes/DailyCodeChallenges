class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int curr=nums[0];
        for(int i=1; i<nums.size(); i++){
        while(nums[i]!=curr+1 && i<nums.size()){
            ans.push_back(curr+1);
            curr++;
        }
        curr=nums[i];
        }
        
        return ans;
    }
};