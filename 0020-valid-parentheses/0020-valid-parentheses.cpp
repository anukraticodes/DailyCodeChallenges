class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
            if(!isclosing(c)) st.push(c);
            else if(!st.empty() && is(st.top(), c)) st.pop();
            else{
                return 0;
            }
        }
        return st.empty();
    }

    bool isclosing(char c){
        if(c==')' || c=='}' || c==']') return 1;
        return 0;
    }

    bool is(char c1, char c2){
        if(c1=='(' && c2!=')') return 0;
        if(c1=='{' && c2!='}') return 0;
        if(c1=='[' && c2!=']') return 0;
        return 1;
    }
};