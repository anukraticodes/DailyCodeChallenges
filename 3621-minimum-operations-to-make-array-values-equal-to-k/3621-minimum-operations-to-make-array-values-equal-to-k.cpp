class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt=0;
        map<int, int> mp;
        if(nums.size()==1){
            if(nums[0]<k) return -1;
            if(nums[0]==k) return 0;
            return 1;
        }
        for(auto num:nums){
            mp[num]++;
        }
        bool flag=0;
        if(mp.find(k)!=mp.end()) flag=1;
        while(mp.size()>1){
            auto it = mp.rbegin();
            if(it->first <=k) return -1;
            int largest=it->first, cnt1=it->second;
            it++;
            int largest2=it->first, cnt2=it->second;
            mp[largest2]+=cnt1;
            mp.erase(largest);
            cnt++;
        }
        auto it=mp.rbegin();
        if(it->first <k) return -1;

        return flag==1?cnt:cnt+1;
    }
};