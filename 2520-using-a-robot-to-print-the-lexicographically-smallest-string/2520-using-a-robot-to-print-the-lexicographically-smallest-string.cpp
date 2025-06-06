class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> mp;
        for(auto it:s) mp[it]++;
        stack<char> st;
        string ans;
        char small='a';
        for(auto it:s){
            st.push(it);
            mp[it]--;
            while(small!='z' && mp[small]==0) small++;
            while(!st.empty() && st.top()<=small){
                ans+=st.top();
                st.pop();
            }
        }
        return ans;
    }
};