class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(!s.size()||!g.size()) return 0;
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());
        int j=0;
        int cnt=0;
        for(int i=0; i<g.size()&&j<s.size(); i++){
            
            if(g[i]<=s[j]){
                cnt++;
                j++;
                }
        }
        return cnt;
    }
};