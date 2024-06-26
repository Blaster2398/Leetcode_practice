//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer = 1;
private:
    void DFS(vector<int>adj[], vector<bool>& visited, vector<int>& dtime, vector<int>& low, vector<bool>& mark, int u, int parent){
        visited[u] = true;
        dtime[u] = low[u] = timer;
        timer++;
        int children = 0;
        
        for(auto v : adj[u]){
            //there are 3 case 
            //case 1 when its a parent 
            if(v == parent) continue;
            
            // if its not visited
            if(!visited[v]){
                DFS(adj, visited, dtime, low, mark, v, u);
                children++;
                // after competon update the low value as usual 
                low[u] = min(low[v], low[u]);
                
                // check for the articulation point condition( and it should not be a root node)
                if(low[v] >= dtime[u] && parent != -1){
                    mark[u] = true;
                }
            }
            
            // if the node is already visited
            else{
                // you cant take the low value of v directly to update the low[u] take dtime of v 
                low[u] = min(low[u], dtime[v]);
            }
        }
        // one more condition for the root node
        if(children > 1 && parent == -1){
            mark[u] = true;
        }
    }
public:
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        //initializations
        vector<bool> visited(V, false);
        vector<int> dtime(V, 0);
        vector<int> low(V,0);
        vector<bool> mark(V, false);
        
        //dfs
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                DFS(adj, visited, dtime, low, mark, 0, -1);
            }
        }
        
        //get the ans vector
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(mark[i] == true){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0) return {-1};
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends