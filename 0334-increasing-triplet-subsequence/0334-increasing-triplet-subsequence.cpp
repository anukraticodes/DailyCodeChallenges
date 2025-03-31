class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
         vector<int> mini(nums.size()), maxi(nums.size());
         int minele=nums[0], maxele=nums[nums.size()-1];
         for(int i=0; i<nums.size(); i++){
            minele=min(nums[i], minele);
            mini[i]=minele;
        }
        for(int i=nums.size()-1; i>=0; i--){
            maxele=max(maxele, nums[i]);
            maxi[i]=maxele;
        }
        for(int i=0; i<nums.size(); i++){
          if(mini[i]<nums[i] && nums[i]<maxi[i]) return 1;

        }
        return 0;
    }
};