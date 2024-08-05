class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map<string, int> mp;
          for(const auto& str : arr) {
            mp[str]++;
        }
        vector<string> v;
        for(const auto&str: arr){
           if(mp[str]==1) v.push_back(str);
        }
        if(k<=v.size()) return v[k-1];
        return "";
    }
};