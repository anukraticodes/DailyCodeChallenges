class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(int i=0; i<s.size(); i++){
            if(isOpen(s[i])){
                s1.push(s[i]);
            }
            else if(isClose(s[i])){
                if(s1.empty()) return 0;
                if(!isMatch(s[i], s1.top())) return 0;
                if(!s1.empty()&&isMatch(s[i], s1.top())){
                    s1.pop();
                }
            }
    }
    return s1.empty();
    }

    bool isOpen(char c){
        if(c=='('||c=='{'||c=='[')
        return 1;
        return 0;
    }

    bool isClose(char c){
        if(c==')'||c=='}'||c==']')
        return 1;
        return 0;
    }

    bool isMatch(char c, char c1){
        if(c==')') return c1=='(';
        if(c=='}') return c1=='{';
        if(c==']') return c1=='[';
        return 0;
    }
};