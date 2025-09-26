class Solution {
private:

    bool dfs(vector<vector<int>>& g, int u, int col, vector<int>& color) {
        color[u] = col;
        for (auto v : g[u]) {
            if (color[v] == -1) {
                if (!dfs(g, v, 1 - col, color)) return false;
            } else if (color[v] == col) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite2(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(graph, i, 0, color)) return false;
            }
        }
        return true;
    }


    void BFS(vector<vector<int>>& graph,vector<int> &color, int u, bool & flag){
        
        color[u] = 0;
        queue<int> q;
        q.push(u);

        while(!q.empty()){
            int ft = q.front();
            q.pop();
            int col = color[ft];
            for(auto v : graph[ft]){
                if(color[v] == -1){
                    color[v] = col ^ 1;
                    q.push(v); 
                }
                else{
                   if(color[v] == col){
                    flag = false;
                    return;
                   } 
                }
            }
        }
    }
public:
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // there are 2 color 0 or 1 
        bool flag = true;
        for( int i = 0; i < n; i++){
            if(color[i] == -1){
                BFS(graph, color, i, flag);
                if (!flag) return false;
            }
        }
        return flag;
    }
};