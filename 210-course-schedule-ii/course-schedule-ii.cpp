class Solution {
public:
    void addEdge(vector<vector<int>>& adj, int u, int v) {
        adj[v].push_back(u);
    }

    bool DFS(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, int u, stack<int>& st) {
        visited[u] = true;
        recStack[u] = true;
        
        for (auto v : adj[u]) {
            if (!visited[v] && DFS(adj, visited, recStack, v, st)) {
                return true;
            } else if (recStack[v]) {
                return true; // Cycle detected
            }
        }

        recStack[u] = false; // Remove from recursion stack
        st.push(u);
        return false;
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        stack<int> st;
        vector<int> res;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (DFS(adj, visited, recStack, i, st)) {
                    return {}; // Return an empty vector if a cycle is detected
                }
            }
        }
        
        while (!st.empty()) {
            int ft = st.top();
            res.push_back(ft);
            st.pop();
        }
        
        return res;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            addEdge(adj, prerequisites[i][0], prerequisites[i][1]);
        }
        
        return topoSort(numCourses, adj);
    }























    // void addEdge(vector<vector<int>>& adj, int u, int v){
    //     adj[v].push_back(u);
    // }
    // vector<int> topo(vector<vector<int>>& adj, int V, vector<int> &res){
        
    //     // calculate the indeg
    //     vector<int> inDeg(V, 0) ;
    //     for(int i = 0; i < V; i++){
    //         for(auto it: adj[i]){
    //             inDeg[it]++;    
    //         }
    //     }

    //     // now do the bfs
    //     queue<int> q;
    //     for(int i =0; i < V; i++){
    //         if(inDeg[i] == 0){
    //             q.push(i);
    //         }
    //     }

    //     while(!q.empty()){
    //         int ft = q.front();
    //         q.pop();
    //         res.push_back(ft);

    //         // decrease the inDeg of adjacents 
    //         for(auto it : adj[ft]){
    //             inDeg[it]--;
    //             if(inDeg[it] == 0){
    //                 q.push(it);
    //             }
    //         }
            
    //     }

    //     // check for cycle 
    //     if(res.size() != V){
    //         return {} ;
    //     }
    //     else{
    //         return res;
    //     }
    // }
    // vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<vector<int>> adj(numCourses);
    //     vector<int> res;
    //     for(int i = 0; i < prerequisites.size(); i++){
    //         addEdge(adj,prerequisites[i][0], prerequisites[i][1] );
    //     }
        

    //     return topo(adj, numCourses, res);
    // }
};