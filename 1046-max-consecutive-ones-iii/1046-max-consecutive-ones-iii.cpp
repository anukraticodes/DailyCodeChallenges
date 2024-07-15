class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0; int r=0; int l=0; int zeros=0; int len=INT_MIN;
        while(r<nums.size()){
            if(nums[r]==0) zeros++;
            while(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            }
            
               
                len=r-l+1;
                maxlen=max(len,maxlen);
            
             r++;
        }
        return maxlen;
    }
};