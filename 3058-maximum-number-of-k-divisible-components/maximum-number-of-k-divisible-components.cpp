class Solution {
public:
    using ll = long long;
    int k;
    vector<int> val;
    vector<int> adj[30001];
    ll dfs(int u, int p, int & count){
        ll temp = 1LL*val[u];
        for(int v : adj[u]){
            if(v != p){
                temp += dfs(v, u, count);
            }
        }
        if((temp % k) == 0){
            count++;
            return 0;
        }
        return temp;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int _k) {
        k = _k;
        val = values;
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int count = 0;
        dfs(0, -1, count);
        return (count == 0) ? 1 : count;
    }
};