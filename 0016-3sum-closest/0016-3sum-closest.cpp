class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=INT_MAX,ret=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int t=target-nums[i];
            int l=i+1, r=nums.size()-1;
            while(l<r){
                int val=abs(target-nums[i]-nums[l]-nums[r]);
                if(val<ans){
                    ans=val;
                    ret=nums[i]+nums[l]+nums[r];
                }
                if((nums[l]+nums[r])>t)r--;
                else if((nums[l]+nums[r])<t)l++;
                else return target;  
            }
        }
        return ret;
    }
};