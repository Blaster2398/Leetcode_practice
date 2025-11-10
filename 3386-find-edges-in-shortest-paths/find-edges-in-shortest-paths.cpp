class Solution {
    using pii= pair<int,int>;
public:
    int n;
    vector<vector<pair<int, int>>> adj;
    // 2 dijskstra problem 
    vector<int> dji(int s){
        vector<int> dis(n, 1e9);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dis[s] = 0;
        pq.push({0, s});

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dis[u]) continue;

            for(auto [v, d1] : adj[u]){
                if(dis[v] > d + d1){
                    dis[v] = d + d1;
                    pq.push({dis[v], v});
                }
            }
        }
        return dis;
    }
    vector<bool> findAnswer(int _n, vector<vector<int>>& edges) {
        n = _n;
        adj.assign(n, {});
        for(auto e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dis1 = dji(0);
        vector<int> dis2 = dji(n-1);

        // now or marking the edges we just have to check from both sides
        int target = dis1[n-1];
        if(target == 1e9) return vector<bool>(edges.size(), false);
        vector<bool> res(edges.size(), false);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if(dis1[u] + w + dis2[v] == target || dis1[v] + w + dis2[u] == target)
                res[i] = true;
        }

        return res;
    }
};