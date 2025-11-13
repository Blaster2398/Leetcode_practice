class Solution {
    using ll = long long;
public:
    vector<ll> p_pow;
    string str;
    vector<bool> res;
    vector<vector<int>> adj;
    const int P = 31, mod = 1e9+7;
    struct node {ll fwd_hash, rev_hash, size;};

    // wee need 3 things from the child < fwd_hash , rev_hash, str_size > 
    node dfs(int u, int p){
        ll curr_fwd = 0;
        ll curr_rev = 0;
        ll curr_size = 0;

        for(auto v : adj[u]){
            if(v != p){
                auto [child_fwd, child_rev, child_size] = dfs(v, u);
                curr_fwd = (curr_fwd * p_pow[child_size] + child_fwd) % mod;
                curr_rev = (child_rev * p_pow[curr_size] + curr_rev) % mod;
                curr_size += child_size;
            }
        }

        // now add the currrent character
        ll curr_char = (str[u]-'a'+1); 
        curr_fwd = (curr_fwd * P + curr_char) % mod;
        curr_rev = (curr_char * p_pow[curr_size] + curr_rev) % mod;

        if(curr_fwd == curr_rev) res[u] = true;
        return {curr_fwd, curr_rev, curr_size+1};
    }

    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = s.size();
        str = s;
        adj.assign(n, {});

        for(int i = 1; i < parent.size(); i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }

        p_pow.resize(n + 1);
        p_pow[0] = 1;
        for (int i = 1; i <= n; i++) {
            p_pow[i] = (1LL * p_pow[i - 1] * P) % mod;
        }

        res.assign(n, false);
        int root = 0;           
        dfs(root, -1);

        return res;
    }
};