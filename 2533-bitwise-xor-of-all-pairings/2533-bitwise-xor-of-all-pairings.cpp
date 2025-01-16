class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(), l2=nums2.size();
        unordered_map<int, long> freq;
        for(int num:nums1) freq[num]+=l2;
        for(int num:nums2) freq[num]+=l1;
        int ans=0;
        for(auto [num, cnt]:freq){
            if(cnt%2==1) ans^=num;
        }
        return ans;
    }
};