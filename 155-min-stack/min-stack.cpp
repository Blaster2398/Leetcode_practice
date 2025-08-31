class MinStack {
public:
    using ll = long long;
    stack<ll> st;
    ll mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else if(val >= mini) {
            st.push(val);
        } 
        else {
            // Encode value
            st.push(2LL * val - mini);
            mini = val;
        }
    }
    
    void pop() {
        if(st.empty()) return ;
        ll tp = st.top();
        st.pop();
        if(tp < mini) mini = 2LL * mini - tp;
    }
    
    int top() {
        if(st.empty()) return -1;
        ll tp = st.top();
        if(tp < mini) return (int)mini;
        else return (int)tp;
    }
    
    int getMin() {
        return (int)mini;
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