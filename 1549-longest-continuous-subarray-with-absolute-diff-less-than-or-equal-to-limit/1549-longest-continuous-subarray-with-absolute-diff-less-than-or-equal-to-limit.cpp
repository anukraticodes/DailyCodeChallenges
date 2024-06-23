class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> inc;
        deque<int> dec;
        int len=0;
        int left=0;

        for(int i=0; i<nums.size(); i++){
            while(!inc.empty() &&nums[i]<inc.back()) inc.pop_back();

            inc.push_back(nums[i]);

            while(!dec.empty()&& nums[i]>dec.back()) dec.pop_back();

            dec.push_back(nums[i]);

            while(dec.front()-inc.front()>limit){
                if(nums[left] == dec.front()) dec.pop_front();

                if(nums[left]== inc.front()) inc.pop_front();

                left++;
            }
            len=max(len, i-left+1);
        }
        return len;
    }
};