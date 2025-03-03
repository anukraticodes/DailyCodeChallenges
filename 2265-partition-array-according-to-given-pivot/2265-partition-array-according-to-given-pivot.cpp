class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v(nums.size(),pivot);
        int cnt=0, k=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<pivot) {
                v[k]=nums[i];
                k++;
            }
            if(nums[i]==pivot){ cnt++;}
            
        }
        k+=cnt;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>pivot) {v[k]=nums[i];
            k++;
            }
        }
        return v;
    }
};