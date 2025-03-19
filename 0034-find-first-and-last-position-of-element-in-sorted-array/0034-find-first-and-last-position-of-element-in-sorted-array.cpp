class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fst=-1, snd=-1;
        fst=bs(nums, target, 1);
        snd=bs(nums, target, 0);
        return {fst, snd};
    }

    int bs(vector<int>& nums, int target, bool l){
        int low=0, high=nums.size()-1, ind=-1;

        while(low<=high){
            int mean=low+(high-low)/2;
            if(nums[mean]>target) high=mean-1;
            else if(nums[mean]<target) low=mean+1;
            else{
                ind=mean;
                if(l) high=mean-1;
                else low=mean+1;
            }
        }
        return ind;
    }
};