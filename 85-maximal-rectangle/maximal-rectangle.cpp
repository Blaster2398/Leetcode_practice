class Solution {
public:
    int largestR(vector<int>& h){
        int n = h.size();
        vector<int> ps(n, -1), ns(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && h[st.top()] >= h[i]) st.pop();
            if(!st.empty()) ps[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && h[st.top()] >= h[i]) st.pop();
            if(!st.empty()) ns[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int nextsmaller = ns[i];
            int prevsmaller = ps[i];
            int range = nextsmaller - prevsmaller -1;
            ans = max(ans, range*h[i]);
        }
        return ans;  
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n == 0 || m == 0) return 0;

        //calculate the prefix sum for all the columns and make a new matrix 
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++){
            if (matrix[0][j] == '1') prefix[0][j] = 1;
            for(int i = 1; i < n; i++){
                if (matrix[i][j] == '1'){
                    prefix[i][j] = prefix[i - 1][j] + 1;
                }
                else{
                    prefix[i][j] = 0;
                }
            }
        }

        int maxArea = 0;

        for(int i = 0; i < n; i++){
            maxArea = max(maxArea, largestR(prefix[i]));
        }

        return maxArea;
    }
};