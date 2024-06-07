//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     void BFS(vector<vector<int>> & adj, vector<bool> &visited, int s, int V){
        queue<int> q;
        visited[s] = true;                 
        q.push(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            visited[u] = true;
            for(int i = 0; i < V; i++){
                if(adj[u][i] == 1 && visited[i] == false){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
  
    int BFS_dis(vector<vector<int>> & adj, int V){
        vector<bool> visited(V,false);
        int count = 0;
        for(int i = 0; i < V; i++){
            if(visited[i] ==false){
                count++;
                BFS(adj,visited,i,V);
            }
        }
        return count;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        
        int count = BFS_dis(adj,V);
        return count;
    }
};






//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends