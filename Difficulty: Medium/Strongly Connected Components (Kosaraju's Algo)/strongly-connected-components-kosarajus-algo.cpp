//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution

{
    private:
    void topo(vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st, int u){
        visited[u] = true;
        
        for(auto v : adj[u]){
            if(visited[v] == false){
                topo(adj, visited, st, v);
            }
        }
        st.push(u);
    }
    void DFS(vector<vector<int>>& adj, vector<bool>& visited, int u){
         visited[u] = true;
        
        for(auto v : adj[u]){
            if(visited[v] == false){
                DFS(adj, visited, v);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // we have 3 steps to do 
        // 1) DFS with topo sort (make a stack and all that is needed )
        vector<bool> visited(V, false);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                topo(adj, visited, st, i);
            }
        }
        
        // 2) we need to reverse the graph 
        vector<vector<int>> rg(V);
        for(int u = 0; u < V; u++){
            for(auto v : adj[u]){
                rg[v].push_back(u);
            }
        }
        
        // 3) now do dfs on the reverse graph with the stack order 
        fill(visited.begin(),visited.end(), false);
        int cnt = 0;
        while(!st.empty()){
            int ft = st.top();
            st.pop();
            if(visited[ft] == true) continue;
            
            DFS(rg, visited, ft);
            cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends