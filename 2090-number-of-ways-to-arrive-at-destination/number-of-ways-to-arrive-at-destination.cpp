#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    void addEdge(vector<vector<pair<int, int>>> &adj, int from, int to, int time) {
        adj[from].push_back({to, time});
        adj[to].push_back({from, time});
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);  // u -> (next, time)

        for (int i = 0; i < roads.size(); i++) {
            addEdge(adj, roads[i][0], roads[i][1], roads[i][2]);
        }

        vector<long long> dist(n, LLONG_MAX);     // Use long long for distances
        vector<long long> path(n, 0);             // Use long long for path counts
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        path[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (time > dist[node]) continue;

            for (auto next : adj[node]) {
                int nextNode = next.first;
                long long weight = next.second;

                if (time + weight < dist[nextNode]) {
                    dist[nextNode] = time + weight;
                    pq.push({dist[nextNode], nextNode});
                    path[nextNode] = path[node];
                }
                else if (time + weight == dist[nextNode]) {
                    path[nextNode] = (path[nextNode] + path[node]) % MOD;
                }
            }
        }

        return path[n - 1];
    }
};
