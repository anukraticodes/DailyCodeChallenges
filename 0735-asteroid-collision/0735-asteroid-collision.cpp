class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
       stack<int> st;
       for(int i=0; i<a.size(); i++){
        if(st.empty()){
            st.push(a[i]);
        }
        else{
            if((st.top()>0 && a[i]<0)){
                while(!st.empty() && abs(st.top())<abs(a[i])){
                    st.pop();
                }
                if(!st.empty() && abs(st.top())==abs(a[i])){
                    st.pop();
                    continue;
                }
                if(st.empty()) st.push(a[i]);
            }
            else{
                st.push(a[i]);
            }
        }
       } 
       vector<int> ans;
       while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
       }
       reverse(ans.begin(), ans.end());
       return ans;
    }
};