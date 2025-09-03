class Solution {
public:
    int dfs(int u, int step, int sum,  vector<vector<pair<int,int>>>& adj, vector<vector<unordered_map<int,int>>>& dp){
        if(step <= 0) return (sum > 0) ? 0 : INT_MIN;
        if(sum < 0) return INT_MIN;
        
        if(dp[u][step].count(sum)) return dp[u][step][sum];

        int ans = -1;
        for(auto [v, w] : adj[u]){
            int srch = dfs(v, step-1, sum-w, adj, dp);
            if(srch == -1) continue;
            ans = max(ans , w + srch);
        }

        return dp[u][step][sum] = ans;
    }
    int maxWeight(int n, vector<vector<int>>& e, int k, int t) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < e.size(); i++){
            int u = e[i][0], v = e[i][1], w = e[i][2];
            adj[u].push_back({v, w});
        }
        // this will store dp of node , step , currSum -> bestans 
        vector<vector<unordered_map<int,int>>> dp(n, vector<unordered_map<int,int>>(k+1));

        int ans = -1;
        for(int i = 0; i < n;i++){
            ans = max(ans , dfs(i,k,t,adj, dp));
        }

        return ans;
    }
};