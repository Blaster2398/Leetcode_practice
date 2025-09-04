class Solution {
public:
    using ll = long long;

    ll dfs(int u, int dis, int inv, int k, vector<vector<int>>& adj, vector<vector<vector<ll>>>& dp, vector<int>& nums, int p) {

        // if (p != -1 && adj[u].size() == 1) {
        //     return inv ? -nums[u] : nums[u];
        // }

        if (dp[u][dis][inv] != LLONG_MIN) 
            return dp[u][dis][inv];

        // Value at this node (depends on inversion parity)
        ll curVal = (inv ? -nums[u] : nums[u]);

        // -------- Option 1: don't invert u --------
        ll opt1 = curVal;
        for (int v : adj[u]) {
            if (v == p) continue;
            int next_dis = max(0, dis - 1);
            opt1 += dfs(v, next_dis, inv, k, adj, dp, nums, u);
        }

        // -------- Option 2: invert u (only if dis == 0) --------
        ll opt2 = LLONG_MIN;
        if (dis == 0) {
            int flipped = 1 - inv;
            ll temp = (flipped ? -nums[u] : nums[u]);
            for (int v : adj[u]) {
                if (v == p) continue;
                temp += dfs(v, k - 1, flipped, k, adj, dp, nums, u);
            }
            opt2 = temp;
        }

        return dp[u][dis][inv] = max(opt1, opt2);
    }

    long long subtreeInversionSum(vector<vector<int>>& e, vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto &edge : e) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k+1, vector<ll>(2, LLONG_MIN)));

        return dfs(0, 0, 0, k, adj, dp, nums, -1);
    }
};
