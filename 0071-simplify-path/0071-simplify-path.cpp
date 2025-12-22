class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;  // ignore empty and current dir
            }
            if (token == "..") {
                if (!st.empty()) st.pop();  // go up one dir
            } else {
                st.push(token);  // valid directory name
            }
        }

        if (st.empty()) return "/";

        string ans;
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
