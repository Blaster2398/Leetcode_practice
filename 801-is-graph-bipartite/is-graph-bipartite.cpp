class Solution {
private:
    void DFS(vector<vector<int>>& graph,int col, int u, bool & flag, vector<int>& color){
        color[u] = col;
        for(auto v : graph[u]){
            if(color[v] == -1){
                DFS(graph,!col,v, flag, color);
            }
            else if(color[v] != !col){
                flag = false;
                break;
            }
            
        }
    }
    void BFS(vector<vector<int>>& graph,vector<bool> &visited,vector<int> &color, int u, bool & flag){
        visited[u] = true;
        color[u] = 0;
        queue<int> q;
        q.push(u);

        while(!q.empty()){
            int ft = q.front();
            q.pop();
            visited[ft] = true;
            int col = color[ft];

            for(auto v : graph[ft]){
                if(visited[v] == false){
                    visited[v] = true;
                    color[v] = !col;
                    q.push(v); 
                }
                else{
                   if(color[v] != !col){
                    flag = false;
                    break;
                   } 
                }
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        bool flag = true;
        for( int i = 0; i < n; i++){
            if(color[i] == -1){
                DFS(graph, 0, i, flag, color);
            }
        }
        return flag;
    }
    // bool isBipartite(vector<vector<int>>& graph) {
    //     int n = graph.size();
    //     vector<bool> visited(n , false);
    //     vector<int> color(n, -1);  // there are 2 color 0 or 1 
    //     bool flag = true;
    //     for( int i = 0; i < n; i++){
    //         if(visited[i] == false){
    //             BFS(graph, visited, color, i, flag);
    //         }
    //     }
    //     return flag;
    // }
};