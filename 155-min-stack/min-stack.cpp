class MinStack {
public:
    stack<int> st;
    // priority_queue<int, vector<int>, greater<int>> pq;
    map<int,int> mp;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        // pq.push(val);
        mp[val]++;
    }
    
    void pop() {
        int t = st.top();
        st.pop();
        if(mp[t] > 0){
            mp[t]--;
        }
        if(mp[t] == 0){
            mp.erase(t);
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto it = mp.begin();

        return it->first;
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