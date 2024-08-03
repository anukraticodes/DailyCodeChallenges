class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        multiset<int> st(target.begin(), target.end());
        multiset<int> st2(arr.begin(), arr.end());
        return st==st2;
    }
};