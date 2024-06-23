//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU
{
    
    public:
    vector<int> rank;
    vector<int> parent;
    
    DSU (int V){
        parent.resize(V);
        rank.resize(V, 0);  
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        else{
            return parent[x] = find(parent[x]);
        }
    }
    
    void union_rank(int x, int y){
        int a = find(x);
        int b = find(y);
        
        if(a == b) return ;
        
        if(rank[a] < rank[b]) parent[a] = b;
        else if(rank[a] > rank[b]) parent[b] = a;
        else{
            parent[b] = a;
            rank[a++];
        }
    }
};

class Solution
{
    // typedef pair<int,int> pair<int,int>;
	
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int cost = 0;
        vector<pair<int, pair<int, int>>> edges;
        for(int u=0; u<V; u++){
            for(int j=0; j<adj[u].size(); j++){
                
                int v = adj[u][j][0];
                int w = adj[u][j][1];
                
                edges.push_back({w, {u, v}});
                
            }
        }
        
        sort(edges.begin(), edges.end());
        
        DSU ds(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int w = edges[i].first;
            
            if(ds.find(u) != ds.find(v)){
                cost+= w;
                ds.union_rank(u,v);
            }
        }
        
        return cost;
    }
    // int spanningTree_Prim(int V, vector<vector<int>> adj[])
    // {
    //     int res = 0;
    //     priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
    //     vector<bool> visited(V, false);
        
    //     pq.push({0,0});
        
    //     while(!pq.empty()){
    //         auto ft = pq.top();
    //         int u = ft.second;
    //         int wt = ft.first;
    //         pq.pop();
            
    //         if(visited[u] == true){
    //             continue;
    //         }
            
    //         visited[u] = true;
    //         res = res + wt;
            
    //         for(auto v : adj[u]){
    //             int nextNode = v[0];
    //             int dis = v[1];
    //             if(visited[nextNode] == false){
    //                 pq.push({dis,nextNode});
    //             }
    //         }
    //     }
        
    //     return res;
    // }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends