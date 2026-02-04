class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> ans(n);
        unordered_map<int, int> mp;
        for(int i=0; i<n;i++){
            mp[nums1[i]]=i;
        }
        stack<int> st;
        for(int i=nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(mp.count(nums2[i])){
               ans[mp[nums2[i]]]= st.empty()?-1:st.top();
            }
            st.push(nums2[i]);
        }
        return ans;
    }
};