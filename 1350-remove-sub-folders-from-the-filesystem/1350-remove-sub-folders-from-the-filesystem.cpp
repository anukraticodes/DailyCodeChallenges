class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        sort(f.begin(), f.end());
        vector<string> ans;
        ans.push_back(f[0]);
        for(int i=1; i<f.size(); i++){
            string curr=ans.back();
            curr.push_back('/');
            if(f[i].compare(0, curr.size(), curr)!=0) ans.push_back(f[i]);
        }
        return ans;
    }
};