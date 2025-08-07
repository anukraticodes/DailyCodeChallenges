class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> len(n, 1), cnt(n, 1);
        int maxilis=INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    if(len[j]+1>len[i]){
                        len[i]=len[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else if(len[j]+1==len[i]){
                         cnt[i]+=cnt[j];
                    }
                }
                
            }
            maxilis=max(len[i], maxilis);
        }
        int res=0;
        for(int i=0; i<n; i++){
            if(len[i]==maxilis) res+=cnt[i];
        }
        return res;
    }
};