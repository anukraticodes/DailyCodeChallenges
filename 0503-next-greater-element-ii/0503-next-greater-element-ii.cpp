class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        for(int i=0; i<=1; i++){
            for(int j=nums.size()-1; j>=0; j--){
                while(!st.empty() && st.top()<=nums[j]) st.pop();
                if(!st.empty() && ans[j]==-1)
               ans[j]=st.top();
                st.push(nums[j]);
            }
        }
        return ans;
    }
};