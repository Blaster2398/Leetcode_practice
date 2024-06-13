class Solution {
public:
    void addEdge(vector<vector<int>>& adj, int u, int v){
        adj[u].push_back(v);
    }

    bool topo(vector<vector<int>>& adj, int V){
        int res = 0;
        // calculate the indeg
        vector<int> inDeg(V, 0) ;
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                inDeg[it]++;    
            }
        }

        // now do the bfs
        queue<int> q;
        for(int i =0; i < V; i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int ft = q.front();
            q.pop();
            res++;

            // decrease the inDeg of adjacents 
            for(auto it : adj[ft]){
                inDeg[it]--;
                if(inDeg[it] == 0){
                    q.push(it);
                }
            }
            
        }

        // check for cycle 
        if(res != V){
            return false ;
        }
        else{
            return true;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++){
            addEdge(adj,prerequisites[i][0], prerequisites[i][1] );
        }
        

        return topo(adj, numCourses);
        
    }
};