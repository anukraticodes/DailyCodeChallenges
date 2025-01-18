class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    multiset<int> st; 
    for (int num : nums) {
        st.insert(num);
    }

    // if (k <= 0 || k > st.size()) {
    //     throw invalid_argument("Invalid value of k");
    // }

    auto it = st.rbegin(); 
    advance(it, k - 1);    
    return *it;            
}
};