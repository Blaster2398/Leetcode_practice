

// class Solution {
// public:
//     const int MOD = 1e9 + 7;

//     void addEdge(vector<vector<pair<int, int>>> &adj, int from, int to, int time) {
//         adj[from].push_back({to, time});
//         adj[to].push_back({from, time});
//     }

//     int countPaths(int n, vector<vector<int>>& roads) {
//         vector<vector<pair<int, int>>> adj(n);  // u -> (next, time)

//         for (int i = 0; i < roads.size(); i++) {
//             addEdge(adj, roads[i][0], roads[i][1], roads[i][2]);
//         }

//         vector<long long> dist(n, LLONG_MAX);     // Use long long for distances
//         vector<long long> path(n, 0);             // Use long long for path counts
//         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

//         dist[0] = 0;
//         path[0] = 1;
//         pq.push({0, 0});

//         while (!pq.empty()) {
//             long long time = pq.top().first;
//             int node = pq.top().second;
//             pq.pop();

//             if (time > dist[node]) continue;

//             for (auto next : adj[node]) {
//                 int nextNode = next.first;
//                 long long weight = next.second;

//                 if (time + weight < dist[nextNode]) {
//                     dist[nextNode] = time + weight;
//                     pq.push({dist[nextNode], nextNode});
//                     path[nextNode] = path[node];
//                 }
//                 else if (time + weight == dist[nextNode]) {
//                     path[nextNode] = (path[nextNode] + path[node]) % MOD;
//                 }
//             }
//         }

//         return path[n - 1];
//     }
// };


class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<pair<int,int>>> adj;
    vector<long long> dist;
    vector<long long> dp;

    long long dfs(int node, int end) {
        if (node == end) return 1; // base: one way to reach end
        if (dp[node] != -1) return dp[node];

        long long ways = 0;
        for (auto [next, w] : adj[node]) {
            if (dist[next] == dist[node] + w) { 
                // only follow edges that are part of shortest paths
                ways = (ways + dfs(next, end)) % MOD;
            }
        }
        return dp[node] = ways;
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        adj.assign(n, {});
        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        // Step 1: Dijkstra to compute shortest distances
        dist.assign(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0,0});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Step 2: DFS + memo over shortest path DAG
        dp.assign(n, -1);
        return dfs(0, n-1);
    }
};
