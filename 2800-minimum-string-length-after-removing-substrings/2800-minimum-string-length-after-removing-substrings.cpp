class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        if(s.size()==0) return 0;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(st.empty()){st.push(s[i]); continue;}
            if(s[i]=='B'&&st.top()=='A') st.pop();
            else if(s[i]=='D'&&st.top()=='C') st.pop();
            else st.push(s[i]);
            

        }
        return st.size();
    }
};