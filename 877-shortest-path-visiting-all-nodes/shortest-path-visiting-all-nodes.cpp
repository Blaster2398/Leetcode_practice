class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // we will store mask , node, dist for the queue state
        int n = graph.size();
        int all_visited = (1 << n) - 1;
        queue<tuple<int,int,int>> q;
        unordered_set<int> visited;

        for(int i = 0; i < n; i++){
            q.push({(1 << i), i, 0});
            visited.insert((1 << i)*16 + i);
        }

        while(!q.empty()){
            auto [mask, node, dist] = q.front(); q.pop();
            if(mask == all_visited) return dist;

            for(auto v : graph[node]){
                int new_mask = mask | (1 << v);
                int vis_hash = new_mask*16 + v;
                if(visited.count(vis_hash) == 0){
                    visited.insert(vis_hash);
                    q.push({new_mask, v, dist+1});
                }
            }
        }
        return -1;
    }
};