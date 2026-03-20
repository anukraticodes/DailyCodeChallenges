class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        vector<int> ans;
        for(int i=0; i<k; i++) st.insert(nums[i]);
        int l=0, r=k;
        while(r<=nums.size()){
            int maxi=*st.rbegin();
            ans.push_back(maxi);
            int value=nums[l++];
            auto it = st.find(value);
            if (it != st.end()) {
                st.erase(it);
            }
            if(r!=nums.size())
            st.insert(nums[r]);
            r++;
        }
        return ans;
    }
};