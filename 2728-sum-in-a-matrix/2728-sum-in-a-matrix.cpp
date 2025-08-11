class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            sort(nums[i].begin(), nums[i].end(), greater<int>());
        }
        int k=0;
        for(int i=0; i<nums[0].size(); i++){
            int val=INT_MIN;
            for(int j=0; j<nums.size(); j++){
               val=max(val, nums[j][k]);
            }
            k++;
            cnt+=val;
        }
        return cnt;
    }
};