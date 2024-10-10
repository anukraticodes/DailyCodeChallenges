class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
    int ans = 0;
    stack<pair<int, int>> st;   

    
    for(int i = 0; i < nums.size(); i++) {
        if(st.empty() || nums[st.top().second] > nums[i]) {
            st.push({nums[i], i});
        }
    }

   
    for(int i = nums.size() - 1; i >= 0; i--) {
        while(!st.empty() && nums[st.top().second] <= nums[i]) {
            ans = max(ans, i - st.top().second);
            st.pop();
        }
    }

    return ans;
}

};