#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int V) {
        parent.resize(V);
        size.resize(V, 1);  // Initialize size vector
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            return parent[x] = find(parent[x]);
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int getSize(int x) {
        int root = find(x);
        return size[root];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU d(n * n);

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        // Union connected 1s using DSU
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int ind = 0; ind < 4; ind++) {
                        int nr = i + dx[ind];
                        int nc = j + dy[ind];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int nodeNo = i * n + j;
                            int adjNodeNo = nr * n + nc;
                            if (d.find(nodeNo) != d.find(adjNodeNo)) {
                                d.unionBySize(nodeNo, adjNodeNo);
                            }
                        }
                    }
                }
            }
        }

        int maxIslandSize = 0;

        // Find the largest island by potentially converting each 0 to 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int currentSize = 1;
                    unordered_set<int> roots;
                    
                    for (int ind = 0; ind < 4; ind++) {
                        int nr = i + dx[ind];
                        int nc = j + dy[ind];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int adjNodeNo = nr * n + nc;
                            int root = d.find(adjNodeNo);
                            if (roots.find(root) == roots.end()) {
                                roots.insert(root);
                                currentSize += d.getSize(root);
                            }
                        }
                    }
                    
                    maxIslandSize = max(maxIslandSize, currentSize);
                }
            }
        }

        return ((maxIslandSize == 0) ? n*n : maxIslandSize);
    }
};