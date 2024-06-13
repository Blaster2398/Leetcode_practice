//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool DFS(vector<int> adj[], vector<bool>&visited, int parent , int  u){
        visited[u] = true;
        
        for(auto v : adj[u]){
            if(visited[v] == false){ 
                if(DFS(adj, visited, u, v ) == true){
                    return true;
                }
            }
            
            // check if that if the node is previously visited then it is not the parent of the 
            // current node ie u
            else if(parent != v){
                return true;
            }
        }
        return false;
    }
    
    bool BFS(vector<int> adj[], vector<bool>& visited, int parent, int u) {
        visited[u] = true;
        queue<pair<int, int>> q;
        q.push({u, parent});
        while (!q.empty()) {
            auto ele = q.front();
            int node = ele.first;
            int par = ele.second;
            q.pop();
    
            for (int v : adj[node]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, node});
                } else if (par != v) {
                    // Found a cycle
                    return true;
                }
            }
        }
        return false;
}

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // step1 initialize a visited arraya and a parent variable which will sore the parent of the 
        //currently in process node 
        int parent =-1;
        vector<bool> visited(V, false);
        
        // step2 do a DFS for disconnected graphs 
        for(int i = 0;i < V; i++){
            if(visited[i] == false){
                // if(DFS(adj,visited, parent,i) == true){
                if(BFS(adj,visited,parent,i) == true){
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends