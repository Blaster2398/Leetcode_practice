class DSU{
    const int mod = 1e9+7;
    public:
    vector<int> parent;
    vector<int> maxVal;
    vector<int> maxValCount;
    DSU(int n, vector<int>& vals){
        parent.resize(n);
        maxVal.resize(n);
        maxValCount.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            maxVal[i] = vals[i];
            maxValCount[i] = 1;
        }
    }

    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void unite(int u, int v, long long& ans){
        int a = find(u);
        int b = find(v);

        if(a == b) return;
        if(maxVal[a] > maxVal[b]){
            parent[b] = a;
        }
        else if(maxVal[b] > maxVal[a]){
            parent[a] = b;
        }
        else{
            parent[a] = b;
            ans+= (1LL*maxValCount[a]*maxValCount[b]) % mod;
            maxValCount[b] += maxValCount[a];
        }
    }
};




class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // make the adj list | and the map of valu-> nodes 
        int n = vals.size();
        vector<vector<int>> adj(n);
        for(auto e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        map<int,vector<int>> val_to_node;
        for(int i = 0; i < n; i++){
            val_to_node[vals[i]].push_back(i);
        }

        // now we make the dsu
        DSU dsu(n, vals);
        long long ans = n;

        for(auto[val, nodes] : val_to_node){
            for(auto u : nodes){
                for(auto v : adj[u]){
                    if(vals[v] <= vals[u]){
                        dsu.unite(u, v, ans);
                    }
                }
            }
        }
        return (int)ans;

    }
};