class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        while(i<j){
            while(nums[i]%2==0 && i<nums.size()-1)i++;
            while(nums[j]%2!=0 && j>0)j--;
            if(i<j)swap(nums[i], nums[j]);
            i++;j--;
        }
        return nums;
    }
};