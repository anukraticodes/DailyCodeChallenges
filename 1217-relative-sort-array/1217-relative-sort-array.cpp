class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;

        for(auto i:arr1){
            mp[i]++;
        }

        vector<int> v;

        for(auto key: arr2){
            auto it=mp.find(key);
            if(it!=mp.end()){
                int freq=it->second;
                for(int j=0; j<freq; j++){
                    v.push_back(it->first);
                }
            }
            mp.erase(it);
        }

       for(map<int, int>:: iterator it2=mp.begin(); it2!=mp.end(); it2++){
        int freq=it2->second;
                for(int j=0; j<freq; j++){
                    v.push_back(it2->first);
                }
            }
       return v;
    }
};