class MinStack {
public:
    stack<int> st;
    stack<int> m;
    MinStack() {    
    }
    
    void push(int val) {
        st.push(val);
        if(m.empty()) m.push(val);
        else{
        stack<int> temp;
        while(!m.empty() && m.top()<val){
            temp.push(m.top());
            m.pop();
        }
        m.push(val);
        while(!temp.empty()){
            m.push(temp.top());
            temp.pop();
        } 
        }
    }
    
    void pop() {
        stack<int> temp;
        while(!m.empty() && m.top()!=st.top()){
            temp.push(m.top());
            m.pop();
        }
        m.pop();
        while(!temp.empty()){
            m.push(temp.top());
            temp.pop();
        }
        st.pop();
    }
    
    int top() {      
        return st.top();
    }
    
    int getMin() {      
        return m.top(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */