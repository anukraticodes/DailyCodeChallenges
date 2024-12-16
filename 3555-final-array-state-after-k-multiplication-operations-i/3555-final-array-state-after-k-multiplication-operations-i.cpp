class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        while(k--){
            int ind=findSmallest(nums);
            nums[ind]*=m;
        }
        return nums;
    }

    int findSmallest(vector<int>& nums){
        int n=nums.size();
        int num=INT_MAX;
        int ind=0;
        for(int i=0; i<n; i++){
            if(nums[i]<num){
                num=nums[i];
                ind=i;
            }
        }
        return ind;
            }
};