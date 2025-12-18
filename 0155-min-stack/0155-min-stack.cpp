class MinStack {
public:
using ll = long long;
    stack<ll> st;
    ll x;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){ st.push(val); x=val;}
        else{
            if(val<x){
                ll p=2LL*val-x;
                st.push(p);
                x=val;
            }
            else st.push(val);
        }
    }
    
    void pop() {
        if(st.top()<x){
            x=2LL*x-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<x) return x;
        return st.top();
    }
    
    int getMin() {
        return x;
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