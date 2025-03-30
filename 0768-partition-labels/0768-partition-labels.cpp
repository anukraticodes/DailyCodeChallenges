class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mp;
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i])==mp.end()){
            mp[s[i]].first=i;
            mp[s[i]].second=-1;
            }
        }
        for(int i=s.size()-1; i>=0; i--){
            if(mp[s[i]].second==-1) mp[s[i]].second=i;
        }
        vector<pair<int, int>> v;
        for(auto it:mp){
            v.push_back({it.second.first, it.second.second});
        }
        sort(v.begin(), v.end());
        // for(auto it:v) cout<<it.first<<" "<<it.second<<endl;
        vector<int> ans;
        int st=-1, end=-1;
        for(auto it:v){
            if(st==-1 && end==-1) st=it.first, end=it.second;
            
            else if(it.first>end){
                // cout<<"flag<<"<<endl;
                // if(it.first==it.second){
                    ans.push_back(end-st+1);
                    st=it.first, end=it.second;    
                
            }
            else if(it.first>st && it.second>end){end=it.second;}
        }
        
        ans.push_back(end-st+1);
        return ans;
    }
};