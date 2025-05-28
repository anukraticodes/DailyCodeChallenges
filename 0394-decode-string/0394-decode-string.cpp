class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]==']'){
                string ans="";
                while(st.top()!="["){
                    ans=st.top()+ans;
                    st.pop();
                }
                st.pop();
                string times="";
                while(!st.empty() && isdigit(st.top()[0])){
                  times=st.top()+times;
                  st.pop();
                }
                int freq=stoi(times);
                string ret="";
                while(freq--) ret=ans+ret;
                st.push(ret);
            }
            else st.push(string(1, s[i]));
        }
        string result="";
        while(!st.empty()){
            result=st.top()+result;
            st.pop();
        }
        return result;
    }
};