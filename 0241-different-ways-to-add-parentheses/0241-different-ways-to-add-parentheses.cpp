class Solution {
public:
    vector<int> diffWaysToCompute(string e) {
        return helper(e);
    }

    vector<int> helper(string s){
        unordered_map<string, vector<int>> dp;
        if(dp.find(s)!=dp.end()) return dp[s];
        vector<int> ans;
        for(int i=0; i<s.size(); i++){
            if(!isdigit(s[i])){
                auto left=helper(s.substr(0,i));
                auto right=helper(s.substr(i+1));

                for(auto& l:left){
                    for(auto& r :right){
                        if(s[i] == '+')
                            ans.push_back(l + r);
                        if(s[i] == '-')
                            ans.push_back(l - r);
                        if(s[i] == '*')
                            ans.push_back(l * r);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(s));
        return dp[s]=ans;
    }
};