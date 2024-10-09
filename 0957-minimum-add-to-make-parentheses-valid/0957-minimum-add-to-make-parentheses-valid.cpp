class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size()==0) return 0;
        stack<char> st;
        int cnt=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') {
                
             st.push(s[i]);
            }
            if(s[i]==')'){
                if(!st.empty()) st.pop();
                else cnt++;
            }
        }
        cnt+=st.size();
        return cnt;
    }
};