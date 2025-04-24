class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans=0;
        unordered_map<int, int> cnt;
        int r=0;
        unordered_set<int> unique(nums.begin(), nums.end());
        int unique_cnt=unique.size();
        for(int l=0; l<nums.size(); l++){
            if(l>0){
                int remove=nums[l-1];
                cnt[remove]--;
                if(cnt[remove]==0) cnt.erase(remove);
            }
            while(r<nums.size() && cnt.size()<unique_cnt){
                int add=nums[r];
                cnt[add]++;
                r++;
            }
            if(cnt.size()==unique_cnt) ans+=(nums.size()-r+1);
        }
        return ans;
    }
};