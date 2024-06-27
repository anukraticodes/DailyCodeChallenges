class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        
        for (int i = 0; i < a.size(); ++i) {
            bool destroyed = false;
            
            while (!st.empty() && a[i] < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(a[i])) {
                    st.pop();
                } else if (abs(st.top()) == abs(a[i])) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            
            if (!destroyed) {
                st.push(a[i]);
            }
        }
        
        vector<int> v(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            v[i] = st.top();
            st.pop();
        }
        
        return v;
    }
};
