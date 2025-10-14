class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // we will aplly bfs in this question 
        queue<int> q;
        q.push(start);
        vector<int> vis(arr.size(), 0);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node] = 1;
            if(arr[node] == 0) return true;

            if(node + arr[node] < arr.size() && !vis[node + arr[node]]) q.push(node + arr[node]);
            if(node - arr[node] >= 0 && !vis[node - arr[node]]) q.push(node - arr[node]);
        }
        return false;
    }
};