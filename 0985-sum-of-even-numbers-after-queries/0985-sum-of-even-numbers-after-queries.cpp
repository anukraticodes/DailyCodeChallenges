class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        int sum=0;
        for(auto it:nums){
            if(it%2==0) sum+=it;
        }
        for(auto it:queries){
            int val=it[0], ind=it[1];
            if(nums[ind]%2==0){
                if(val%2==0) sum+=val;
                else sum-=nums[ind];
            }
            else{
                if(val%2!=0) sum+=(nums[ind]+val);
            }
            nums[ind]+=val;
            ans.push_back(sum);
        }
        return ans;
    }
};