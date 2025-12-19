class Solution {
public:
    bool isNumber(const string& s) {
        try {
            stoi(s);
            return true;
        } catch (...) {
            return false;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto &tok : tokens) {
            if (isNumber(tok)) {
                st.push(stoi(tok));
            } else {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();

                if (tok == "+") st.push(b + a);
                else if (tok == "-") st.push(b - a);
                else if (tok == "*") st.push(b * a);
                else st.push(b / a);  
            }
        }
        return st.top();
    }
};
