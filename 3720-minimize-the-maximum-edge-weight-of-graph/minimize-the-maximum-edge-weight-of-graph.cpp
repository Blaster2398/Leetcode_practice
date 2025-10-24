class Solution {
public:
    vector<int> out;
    vector<vector<pair<int,int>>> adj;
    vector<int> vis;
    int n, threshold;
    int vis_count;
    void dfs(int u, int mid){
        vis[u] = 1;
        vis_count++;
        for(auto [w, v] : adj[u]){
            if(w > mid) break;
            if(out[v] < threshold){
                out[v]++;
                if(!vis[v]){
                    dfs(v, mid);
                }
            }
        }
    }

    bool check(int mid){
        out.assign(n, 0);   
        vis.assign(n, 0);
        vis_count = 0;
        dfs(0, mid);
        return (vis_count == n);
    }

    int minMaxWeight(int _n, vector<vector<int>>& edges, int _threshold) {
        n = _n;
        adj.resize(n);
        threshold = _threshold; 
        
        int low = INT_MAX;
        int high = INT_MIN;

        bool hasEdge = false;
        for(auto e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[v].push_back({w, u});
            low = min(w, low);
            high = max(w, high);
            hasEdge = true;
        }

        if(!hasEdge) return -1;
        if(n == 1) return 0;


        for(int i = 0; i < n; i++){
            sort(adj[i].begin(), adj[i].end());
        }
        int ans = -1;
        while(low <= high){
            int mid = (low+high) >> 1;
            if(check(mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};