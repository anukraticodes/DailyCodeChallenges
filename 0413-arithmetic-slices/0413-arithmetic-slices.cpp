class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int r=0, l=0, prev=nums[0]-nums[1], diff=0, cnt=0;
        for(r=2; r<nums.size(); r++){
             diff=nums[r-1]-nums[r];
             if(prev==diff && (r-l+1)==3) cnt++;
             if(prev==diff && (r-l+1)>3) cnt+=r-l-1;
             if(prev!=diff){
                l=r-1;
            }
            prev=diff;
        }
        return cnt;
    }
};