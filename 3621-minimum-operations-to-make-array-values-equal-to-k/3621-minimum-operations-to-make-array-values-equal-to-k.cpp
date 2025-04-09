class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st(nums.begin(), nums.end());
        int mini=*st.begin();
        if(mini<k) return -1;
        int ans=st.size();
        return st.count(k)? ans-1:ans;
    }
};