class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // we need to find the previous smaller nd the next smaller in each point 
        int n = heights.size();
        vector<int> ps(n, -1), ns(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) ps[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) ns[i] = st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int nextsmaller = ns[i];
            int prevsmaller = ps[i];
            int range = nextsmaller - prevsmaller -1;
            ans = max(ans, range*heights[i]);
        }
        return ans;   
    }
};