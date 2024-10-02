class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        unordered_map<int, int> ranks;
        int rank=1;
        for(auto& num:s){
            ranks[num]=rank++;
        }
        for(auto& num:arr){
            num=ranks[num];
        }
        return arr;
    }
};