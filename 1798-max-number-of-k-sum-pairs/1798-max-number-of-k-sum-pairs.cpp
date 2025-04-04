class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        int left=0,right=n-1;
        while(left<right)
        {
            int sum = nums[left]+nums[right];
            if(sum==k)
            {
                count++;
                left++;
                right--;
            }
            else if(sum>k)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return count;
    }
};