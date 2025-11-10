#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int farthest;
    int maxdep = -1;
    void dfs(int u, int p, int d, vector<int>& dis, vector<vector<int>>& adj){
        dis[u] = d;
        if(maxdep < d){
            maxdep = d;
            farthest = u;
        }
        for(auto v : adj[u]){
            if(v != p) dfs(v, u, d+1, dis, adj);
        }
    }

    vector<int> geek(vector<vector<int>>& adj, int n){
        if(n == 1) return {0}; 
        vector<int> temp(n, 0), dis1(n, 0), dis2(n,0);

        maxdep = -1; 
        dfs(0, -1, 0, temp, adj);
        int one = farthest;

        maxdep = -1; 
        dfs(one, -1, 0, dis1, adj);

        maxdep = -1;
        int two = farthest;
        dfs(two, -1, 0, dis2, adj);

        vector<int> res(n, -1);
        for(int i = 0; i < n; i++){
            res[i] = max(dis1[i], dis2[i]);
        }
        return res;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = 0, m = 0;
        
        if (edges1.empty()) {
            n = 1; 
        } else {
            int max_n = 0;
            for(auto& e : edges1) {
                max_n = max({max_n, e[0], e[1]});
            }
            n = max_n + 1; 
        }

        if (edges2.empty()) {
            m = 1; 
        } else {
            int max_m = 0;
            for(auto& e : edges2) {
                max_m = max({max_m, e[0], e[1]});
            }
            m = max_m + 1;
        }

        vector<vector<int>> adj1(n), adj2(m);
        for(auto e : edges1){
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for(auto e : edges2){
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        vector<int> dis1 = geek(adj1, n);
        vector<int> dis2 = geek(adj2, m);

        
        int mx1 = *max_element(dis1.begin(), dis1.end());
        int mx2 = *max_element(dis2.begin(), dis2.end());
        int mn1 = *min_element(dis1.begin(), dis1.end());
        int mn2 = *min_element(dis2.begin(), dis2.end());

        return max({mx1, mx2, mn1 + mn2 + 1});
    }
};