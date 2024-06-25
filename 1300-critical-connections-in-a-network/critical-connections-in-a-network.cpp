class Solution {
private:
    int timer = 1;
private:
    void DFS(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& time, vector<int> & low,int u, int parent, vector<vector<int>>& bridges){
        visited[u] = true;

        time[u] = low[u] = timer;
        timer++;

        for(auto v : adj[u]){
            //either its the parent 
            if(v == parent) continue;

            if(!visited[v]){
                DFS(adj, visited, time, low, v, u, bridges);
                // after the dfs traversal is over the node u will ask for node v's low
                low[u] = min(low[u],low[v]);
                // check if this u--v bond can be a bridge (low v should be greater than time of u)
                if(low[v] > time[u]){
                    bridges.push_back({u,v});
                }
            }
            // if v already visited and  not u's parent then u--v can never become a bridge as it can be reached through other route
            // but it can help update the low value may be the low of v is less than u's low 
            else{
                low[u] = min(low[u],low[v]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n,vector<vector<int>>& connections) {
        // make the adjacency list
        vector<vector<int>> adj(n);
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // initialization 
        vector<bool> visited(n, false);
        vector<int> time(n,0);
        vector<int> low(n,0);
        vector<vector<int>> bridges;

        // call for DFS
        DFS(adj, visited, time, low, 0, -1,bridges);

        return bridges;
    }
};