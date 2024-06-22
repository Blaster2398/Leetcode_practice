class Solution {
public:
    void addEdge( vector<vector<pair<int,int>>> & adj, int from , int to, int price){
        adj[from].push_back({to, price});
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);  /// u-> next, dist

        for(int i = 0; i < flights.size(); i++){
            addEdge(adj,flights[i][0], flights[i][1], flights[i][2]);
        }
        // here we will be storing {stops, {node, dist}}
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n, 1e9);
        
        q.push({0,{src, 0}});
        dist[src] = 0;
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;

            q.pop();

            if(stop > k) continue;

            
            for(auto next : adj[node]){
                int nextNode = next.first;
                int weight = next.second;

                // If the distance to the next node is shorter through the current node
                if (dis + weight < dist[nextNode]) {
                    dist[nextNode] = dis + weight;
                    q.push({stop + 1, {nextNode, dist[nextNode]}});
                }
            }
        }
        
        return (dist[dst] != 1e9)? dist[dst] : -1;

    }
};
