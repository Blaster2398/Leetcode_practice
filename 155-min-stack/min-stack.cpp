class MinStack {
public:
    stack<long long> st;
    long long mini = INT_MAX;

    MinStack() {
        while(!st.empty()) st.pop();
    }

    void push(int value) {
        long long val = value;
        if(st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if(val < mini) {
                st.push(2*val*1LL - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if(st.empty()) return;

        long long t = st.top();
        st.pop();
        if(t < mini) {
            mini = 2*mini - t;
        }
    }

    int top() {
        if(st.empty()) return -1;
        long long t = st.top();
        if(t < mini) {
            return mini;
        } else {
            return t;
        }
    }

    int getMin() {
        return mini;
    }





//     stack<int> st;
//     // priority_queue<int, vector<int>, greater<int>> pq;
//     map<int,int> mp;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         st.push(val);
//         // pq.push(val);
//         mp[val]++;
//     }
    
//     void pop() {
//         int t = st.top();
//         st.pop();
//         if(mp[t] > 0){
//             mp[t]--;
//         }
//         if(mp[t] == 0){
//             mp.erase(t);
//         }
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         auto it = mp.begin();

//         return it->first;
//     }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */