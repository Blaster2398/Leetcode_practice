//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool DFS(vector<int> adj[],int V, vector<bool>& visited, vector<bool>& recStack, int u){
        visited[u] =true;
        
        recStack[u] =true;
        
        for(auto v : adj[u]){
            if(visited[v] == false && DFS(adj, V, visited, recStack, v) == true){
                return true;
            }
            
            // this means that v is already a member of the current dfs stack and is revisited
            else if(recStack[v] == true){
                return true;
            }
        }
        
        recStack[u] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // initialization 
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        
        //go through all disconnected parts
        for(int i =0; i < V; i++){
            if(visited[i] == false){
                if(DFS(adj, V, visited, recStack,i)== true){
                    return true;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends