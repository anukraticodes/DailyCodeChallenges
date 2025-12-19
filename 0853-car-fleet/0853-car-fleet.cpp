class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        vector<pair<int, int>> v;
        for(int i=0; i<p.size(); i++){
            v.push_back({p[i], s[i]});
        }
        sort(v.rbegin(), v.rend());
        stack<double> st;
        for(auto c:v){
            double time = (double)(target - c.first) / c.second;
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }
        return st.size();
    }
};