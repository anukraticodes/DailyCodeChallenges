class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        left[0]=0;
        right[nums.size()-1]=0;
        int sum=0;
        for(int i=0;i <nums.size()-1; i++){
            sum+=nums[i];
            left[i+1]=sum;
        }
        sum=0;
        for(int i=nums.size()-2; i>=0; i--){
            sum+=nums[i+1];
            right[i]=sum;
        }
        for(int i=0; i<nums.size(); i++){
            cout<<left[i]<<" "<<right[i]<<endl;
            if(left[i]==right[i]) return i;
        }
        return -1;
    }
};