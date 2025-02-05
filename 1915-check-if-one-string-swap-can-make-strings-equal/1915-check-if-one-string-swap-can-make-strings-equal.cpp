class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int cnt=0;
        unordered_map<char, int> st;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]) {
                cnt++;
                if(st.empty() || st.find(s1[i])==st.end() || st.find(s2[i])==st.end()){
                st[s1[i]]=1;
                st[s2[i]]=2;
                }
                else{
                    if(st.find(s1[i])!=st.end() && st[s1[i]]==1)
                    return false;
                    if(st.find(s2[i])!=st.end() && st[s2[i]]==2)
                    return false;
                }
            }
        }
        return cnt==2 && st.size()==2 && s1.size()!=2;
    }
};