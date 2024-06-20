class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> nextGreater;
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; --i) {
           
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            
            
            if (!s.empty()) {
                nextGreater[nums2[i]] = s.top();
            } else {
                nextGreater[nums2[i]] = -1;
            }
            
           
            s.push(nums2[i]);
        }
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        
        return result;
    }
};