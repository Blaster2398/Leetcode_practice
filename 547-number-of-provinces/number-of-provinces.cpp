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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected[0].size();
        cout << V << " ";
        int count = BFS_dis(isConnected,V);
        return count;
    }
};