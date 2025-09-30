class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int j=nums.size();
        int i=0;
        
        for(i=0; i<j-1; i++){
            nums[i]=(nums[i]+nums[i+1])%10;
            
            if(i==j-2) {i=-1; j--;}
        }
    
        
        return nums[0];
    }
};