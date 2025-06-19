class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt=0;
        int min=nums[0];
        for(int i=0; i<nums.size(); i++){
            if((nums[i]-min)>k){
                min=nums[i];
                cnt++;
            }
        }
        return cnt+1;
    }
};