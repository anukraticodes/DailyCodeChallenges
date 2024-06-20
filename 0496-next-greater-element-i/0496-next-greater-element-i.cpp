class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        map<int, int> mp;
        for(int i=0; i<nums2.size()-1; i++){
            for(int j=i+1; j<nums2.size(); j++){
                if(nums2[j]>nums2[i]){
                    mp[nums2[i]]=nums2[j];
                    break;
                }
            }
        }
        for(int i=0; i<nums1.size(); i++){
            auto it=mp.find(nums1[i]);
            if(it!=mp.end())
            v.push_back(it->second);
            else
            v.push_back(-1);
        }
        return v;
    }
};