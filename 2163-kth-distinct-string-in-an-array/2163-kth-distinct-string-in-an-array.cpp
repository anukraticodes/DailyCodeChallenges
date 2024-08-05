class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map<string, int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        vector<string> v;
        for(auto str: arr){
           if(mp[str]==1) v.push_back(str);
        }
        if(k<=v.size()) return v[k-1];
        return "";
    }
};