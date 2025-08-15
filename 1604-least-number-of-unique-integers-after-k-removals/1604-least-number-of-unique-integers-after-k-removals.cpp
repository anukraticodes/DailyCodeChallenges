class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++) mp[arr[i]]++;
        multiset<int> st;
        for(auto it:mp) st.insert(it.second);
        auto it=st.begin();
        while(k>0 && it!=st.end()){
          it=st.begin();
          if(*it<=k){
            k-=*it;
            st.erase(it);
          }
          else{
            break;
          }  
        }
        return st.size();
    }
};