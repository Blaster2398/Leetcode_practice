class Solution {
public:
    vector<int> nums;
    vector<int> adj[1001];
    vector<int> xer;
    int ans = INT_MAX;
    vector<int> parent;
    int dfs(int u, int p) {
        parent[u]= p;
        int xr = nums[u];
        for (auto v : adj[u]) {
            if (v != p) xr ^= dfs(v, u);
        }
        xer[u] = xr;
        return xr;
    }


    void dfs2(int u, int p, int x, int total) {
        for (auto v : adj[u]) {
            if (v == p) continue;

            int x1, x2;
            if (v == parent[u]) {
                // The component cut off is "everything above u"
                x1 = xer[0] ^ xer[u]; 
                x2 = total ^ x1;
            } else {
                // We are moving "down" to a child
                x1 = xer[v];
                x2 = total ^ x1;
            }
            ans = min(ans, max({x1, x, x2}) - min({x1, x, x2}));
            dfs2(v, u, x, total);
        }
    }


    void dfs1(int u, int p) {
        for (int v : adj[u]) {
            if (v == p) continue;
            int x1 = xer[v];
            int x2 = xer[0] ^ x1;
            dfs2(v, u, x2, x1);
            dfs2(u, v, x1, x2);

            dfs1(v, u);
        }
    }
    

    int minimumScore(vector<int>& num, vector<vector<int>>& edges) {
        int n = num.size();
        if(n <= 2) return 0;
        nums = num;
        parent.assign(n, -1);
        xer.assign(n, 0);
        ans = INT_MAX;

        for (int i = 0; i < n; i++) adj[i].clear();

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        dfs1(0, -1);
        return ans;
    }
};