class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(n<2) return 0;
        if(k==1){
            return 1;
        }
        if(n==2*k){
            bool flag=0;
            for(int j=0; j<k-1; j++){
                if(nums[j]>=nums[j+1] || nums[j+k]>=nums[j+k+1]){
                    flag=1; 
                }
            }
            if(flag==0) return 1;
        }
        else{
        for(int i=0; i<=n-(2*k); i++){
            bool flag=0;
            for(int j=0; j<k-1; j++){
                if(nums[i+j]>=nums[i+j+1] || nums[i+j+k]>=nums[i+j+k+1]){
                    flag=1; break;
                }
            }
            if(flag==0) return 1;
        }
        }
        return 0;
    }
};