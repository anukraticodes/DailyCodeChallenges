class Solution {
public:
     void flip(vector<int>& nums, int ind){
        int x=3;
        while(x--){
            if(nums[ind]==0) nums[ind]=1;
            else nums[ind]=0;
            ind++;
        }
     }

    int minOperations(vector<int>& nums) {
       int cnt=0, n=nums.size();
       for(int i=0; i<nums.size()-2; i++){
        if(nums[i]==0){
            flip(nums, i);
            cnt++;
        }
       } 
       if(nums[n-2]==0 || nums[n-1]==0) return -1;
       return cnt;
    }
};