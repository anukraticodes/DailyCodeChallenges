class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto it:operations){
            if(it=="+"){
                int op1=st.top();
                st.pop();
                int op2=st.top();
                int sum=op1+op2;
                st.push(op1);
                st.push(sum);
            }
            else if(it=="C") st.pop();
            else if(it=="D") st.push(2*st.top());
            else st.push(stoi(it));
        }
        int ans=0;
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
        return ans;
    }
};