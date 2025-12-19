class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto ch:tokens){
            char s=ch[0];
            if(ch.size() > 1 || isdigit(ch[0])){
                st.push(stoi(ch));
            }
            else{
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                int ans=call(op1, op2, ch);
                st.push(ans);
            }
        }
        return st.top();
    }

    int call(int a, int b, string s){
        if(s=="+") return a+b;
        if(s=="-") return b-a;
        if(s=="*") return a*b;
        else return b/a;
    }
};