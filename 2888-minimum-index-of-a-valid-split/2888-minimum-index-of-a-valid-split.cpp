class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dom=-1, domcnt=-1;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second>nums.size()/2){
                dom=it.first;
                domcnt=it.second;
            }
        }
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