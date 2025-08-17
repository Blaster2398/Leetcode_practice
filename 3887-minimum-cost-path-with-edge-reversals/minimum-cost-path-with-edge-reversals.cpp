class Solution {
public:
using ll = long long ;
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, ll>>> adj(n);
        for(auto e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, 1LL*w});
            adj[v].push_back({u, 1LL*w*2});
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, 0*1LL});
        const ll INF = 1e18;
        vector<ll> dist(n, 1e18);
        dist[0] = 0;
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            for(auto [v, w] : adj[u]){
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return (dist[n-1] != 1e18) ? (int)dist[n-1] : -1;
    }
};