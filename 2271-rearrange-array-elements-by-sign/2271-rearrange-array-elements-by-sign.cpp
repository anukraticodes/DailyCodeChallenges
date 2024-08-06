class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v, p, n;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0) n.push_back(nums[i]);
            else p.push_back(nums[i]);
        }
        int i=0, j=0;
        while(i<p.size() && j<n.size()){
            v.push_back(p[i]);
            i++;
            v.push_back(n[j]);
            j++;
        }
        return v;
    }
};