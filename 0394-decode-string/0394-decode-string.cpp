class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(int i=0; i<s.size();i++){
            if(s[i]==']'){
                string curr="";
                while(st.top()!="["){
                    curr=st.top()+curr;
                    st.pop();
                }
                st.pop();
                string times="";
                while(!st.empty() && isdigit(st.top()[0])){
                    times=st.top()+times;
                    st.pop();
                }
                int f=stoi(times);
                string p="";
                while(f--) p+=curr;
                st.push(p);
            }
            else{
                st.push(string(1, s[i]));
            }
        }
        string ret="";
        while(!st.empty()){
            ret=st.top()+ret;
            st.pop();
        }
        return ret;
    }
};