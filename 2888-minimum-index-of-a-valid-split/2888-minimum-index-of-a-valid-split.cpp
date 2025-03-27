class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dom=nums[0], domcnt=0, count=0;
        for(auto& num:nums){
            if(num==dom) count++;
            else count--;
            if(count==0){
                dom=num;
                count=1;
            }
        }
        for(auto& num:nums){
            if(num==dom) domcnt++;
        }
        // unordered_map<int, int> mp;
        // for(int i=0; i<nums.size(); i++){
        //     mp[nums[i]]++;
        // }
        // for(auto it:mp){
        //     if(it.second>nums.size()/2){
        //         dom=it.first;
        //         domcnt=it.second;
        //     }
        // }
        int valid=-1, cnt=0;
        for(int i=0; i<nums.size(); i++){
           if(nums[i]==dom) cnt++;
           if(cnt>(i+1)/2){
            valid=i;
            break;
           }
        }
        if((domcnt-cnt)>(nums.size()-(valid+1))/2) return valid;
        return -1;
    }
};