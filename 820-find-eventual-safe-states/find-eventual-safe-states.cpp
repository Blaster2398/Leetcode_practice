class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& state) {
        if (state[u] > 0) return state[u] == 2;  // already processed

        state[u] = 1; // visiting
        for (auto v : graph[u]) {
            if (!dfs(v, graph, state)) 
                return false; // cycle detected
        }
        state[u] = 2; // safe
        return true;
    }



    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> rg(n);
        vector<int> inD(n , 0);
        for(int i = 0; i < n; i++){
            for(auto v : adj[i]){
                rg[v].push_back(i);
                inD[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!inD[i]) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int top = q.front(); q.pop();
            ans.push_back(top);
            for(auto v : rg[top]){
                inD[v]--;
                if(!inD[v]) q.push(v);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
