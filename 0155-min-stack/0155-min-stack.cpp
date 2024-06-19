class MinStack {
    stack<pair<long long, long long>> s;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long value=val;
        if(s.empty()){
            s.push({value, value});
            return;
        }
        if(value<s.top().second){
            s.push({value,value});
            return;
        }
        s.push({value, s.top().second});

    }
    
    void pop() {
        if(s.empty()) return;
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return s.top().second;
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