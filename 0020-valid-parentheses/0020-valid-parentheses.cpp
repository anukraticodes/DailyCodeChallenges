class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // if(isclosing(s[0])) return 0;
        for(auto c:s){
            if(!isclosing(c)) st.push(c);
            else if(st.empty() && isclosing(c)) return 0;
            else{
                if(!is(st.top(), c)) return 0;
                else st.pop();
            }
        }
        if(!st.empty()) return 0;
        return 1;
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