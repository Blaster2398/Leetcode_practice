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

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0), ans;
        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state)) ans.push_back(i);
        }
        return ans;
    }
};
