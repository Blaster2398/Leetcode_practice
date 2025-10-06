class Solution {
public:
    int ans = 0;
    vector<bool> vis;
    vector<vector<int>> adj;
    void dfs(int u){
        vis[u] = true;
        for(auto v : adj[u]){
            if(!vis[abs(v)]){
                ans += (v > 0);
                dfs(abs(v));
            }
        }
    } 
    int minReorder(int n, vector<vector<int>>& connections) {
        // we will do a dfs from the root node 0 to all the nodes that can be reached
        adj.assign(n, {});
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(-u);
        }
        vis.assign(n, false);
        dfs(0);
        return ans;
    }
};