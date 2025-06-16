class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        stack<int> st;
        int ans=-1;
        st.push(nums[0]);
        for(int i=1; i<nums.size(); i++){
           if(st.top()>=nums[i]){
            st.pop();
            st.push(nums[i]);
           }
           else{
            ans=max(ans, nums[i]-st.top());
           }
        }
        return ans;
    }
};