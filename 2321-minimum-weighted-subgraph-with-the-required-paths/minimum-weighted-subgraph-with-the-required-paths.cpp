class Solution {
public:
    using ll = long long ;

    vector<ll> dji(vector<vector<pair<int,int>>> & adj, int u){
        priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<>> pq;
        vector<ll> dist(adj.size(), 1e18);
        dist[u] = 0;
        pq.push({0,u});
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto [v, d2] : adj[u]){
                if(d + d2 < dist[v]){
                    dist[v] = d+d2;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<pair<int,int>>> rg(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            rg[v].push_back({u, w});
        }

        vector<ll> d1 = dji(adj, src1);
        vector<ll> d2 = dji(adj, src2);
        vector<ll> d3 = dji(rg, dest);

        ll mini = 1e18;
        for(int i = 0; i < n; i++){
            mini = min(mini, d1[i] + d2[i] + d3[i]);
        }

        return mini == 1e18 ? -1 : mini;



    }
};