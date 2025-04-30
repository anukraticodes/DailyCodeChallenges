class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long count = 0;
        int max_num = *max_element(nums.begin(), nums.end());
        int j = 0;
        int countMax = 0;

        for(int i = 0; i < n; i++){
            if(max_num == nums[i]) countMax++;

            while(countMax >= k){
                count += n - i;
                if(nums[j] == max_num) countMax--;
                j++;
            }
        }

        return count;
    }
};