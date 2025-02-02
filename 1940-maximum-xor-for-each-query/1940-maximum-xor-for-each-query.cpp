class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int m) {
    int n = nums.size();
    vector<int> ans;
    
    int x=nums[0];
    ans.push_back(x xor ((1<<m)-1));  

    for (int i = 1; i < n; i++) {
        x=x xor nums[i];  // XOR the current number with the cumulative XOR
        ans.push_back(x xor ((1<<m)-1));
        
    }

    reverse(ans.begin(), ans.end());  // Reverse to match the required order
    return ans;
}
};