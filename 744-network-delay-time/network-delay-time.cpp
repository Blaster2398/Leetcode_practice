class Solution {
public:
    void addEdge( vector<vector<pair<int,int>>> & adj, int from , int to, int time){
        adj[from].push_back({to, time});
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);  /// u-> next, time

        for(int i = 0; i < times.size(); i++){
            addEdge(adj,times[i][0]-1, times[i][1]-1, times[i][2]);
        }

        vector<int> dist(n, 1e9);
        priority_queue<pair<int,int> , vector<pair<int, int>>, greater<pair<int,int>>> pq;

        dist[k-1] = 0;
        pq.push({0, k-1});

        while(!pq.empty()){
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            
            for(auto next : adj[node]){
                int nextNode = next.first;
                int weight = next.second;

                if(time + weight < dist[nextNode]){
                    dist[nextNode] = time + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int maxi = *max_element(dist.begin(),dist.end());

        return (maxi != 1e9) ? maxi : -1;



    }
};