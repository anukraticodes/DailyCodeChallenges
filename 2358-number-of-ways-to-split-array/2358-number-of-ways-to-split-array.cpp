class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long int cnt=0;
        vector<long long int> ans(nums.size());
        long long int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            ans[i]=sum;
        }
        for(int i=0; i<nums.size()-1; i++){
            long long int sum1=ans[nums.size()-1]-ans[i];
        //    for(int j=i+1; j<nums.size(); j++){
        //           sum1+=nums[j];
        //    }
           if(ans[i]>=sum1) cnt++;
        }        
        return cnt;
    }
};