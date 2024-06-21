//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
	void DFS(vector<vector<pair<int,int>>> & adj, vector<bool>&visited, int  u, stack<int> & st){
        visited[u] = true;
        
        for(auto v : adj[u]){
            if(visited[v.first] == false){ 
                DFS(adj, visited, v.first,st );
            }
        }
        st.push(u);
    }
    void addEdge(vector<vector<pair<int,int>>>& adj , int u, int v, int wt){
        adj[u].push_back({v, wt});

    }
    
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(N);
        for(int i = 0; i < M; i++){
            addEdge(adj, edges[i][0], edges[i][1], edges[i][2]);
        }
        
        vector<bool> visited(N, false);
        stack<int> st;
        for(int i = 0; i < N; i++){
            if(visited[i] == false){
                DFS(adj, visited, i, st);
            }
        }
        
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        
        while(!st.empty()){
            int ft = st.top();
            st.pop();
            
            for(auto v : adj[ft]){
                int node = v.first;
                int wt = v.second;
                if(dist[ft] + wt < dist[node]){
                    dist[node] = dist[ft] + wt;
                }
            }
        }
        
        for(int i =0; i < dist.size(); i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends