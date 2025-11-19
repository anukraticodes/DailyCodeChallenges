class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st;
        for(auto n:nums) st.insert(n);
        while(true){
            if(st.count(original)) original=original*2;
            else break;
        }
        return original;
    }
};