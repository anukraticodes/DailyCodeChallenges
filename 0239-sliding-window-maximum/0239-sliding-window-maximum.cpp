class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        vector<int> ans;
        for(int i=0; i<k; i++) st.insert(nums[i]);
        int l=0, r=k;
        for(r=k; r<nums.size(); r++){
            int maxi=*st.rbegin();
            ans.push_back(maxi);
            int value=nums[l++];
            auto it = st.find(value);
            if (it != st.end()) {
                st.erase(it);
            }
            st.insert(nums[r]);
        }
        int maxi=*st.rbegin();
        ans.push_back(maxi);
        return ans;
    }
};