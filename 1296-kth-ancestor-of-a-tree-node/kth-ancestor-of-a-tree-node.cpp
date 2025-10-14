class TreeAncestor {
private:
    static const int MAXN = 50001;
    static const int LOGN = 17;

    vector<int> adj[MAXN];
    int depth[MAXN];
    int up[MAXN][LOGN];

    void dfs(int u, int p, int d){
        depth[u] = d;
        up[u][0] = p;
        for(auto v : adj[u]){
            if(v != p){
                dfs(v, u, d+1);
            }
        }
    }

    void preCompute(int N){
        dfs(0, -1, 0);
        for(int j = 1; j < LOGN; j++){
            for(int u = 0; u < N; u++){
                if(up[u][j-1] != -1) up[u][j] = up[ up[u][j-1] ][j-1];
                else up[u][j] = -1;
            }
        }
    }
public:
    TreeAncestor(int n, vector<int>& parent) {
        // create the adj list 
        for(int i = 1; i < n; i++){
            int u = i;
            int v = parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // initialize the up array 
        memset(up, -1, sizeof(up));
        // precompute 
        preCompute(n);
    }
    
    int getKthAncestor(int u, int k) {
        for(int j = LOGN-1; j >= 0; j--){
            if(k & (1 << j)){
                u = up[u][j];
                if(u == -1) return -1;
            }
        }
        return u;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */