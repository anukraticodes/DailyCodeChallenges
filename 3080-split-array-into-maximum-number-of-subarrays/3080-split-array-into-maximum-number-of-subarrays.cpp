class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int cnt=0;
        int val=-1;
        for(auto n:nums){
            val&=n;
            if(val==0){
                cnt++;
                val=-1;
            }
        }
        return cnt==0?1:cnt;
    }
};