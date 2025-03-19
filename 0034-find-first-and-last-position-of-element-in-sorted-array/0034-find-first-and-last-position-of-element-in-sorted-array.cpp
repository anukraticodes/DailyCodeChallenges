class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fst=-1, snd=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target) {
                fst=i;
                break;
            }
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]==target){
                snd=i;
                break;
            }
        }
        return {fst, snd};
    }
};