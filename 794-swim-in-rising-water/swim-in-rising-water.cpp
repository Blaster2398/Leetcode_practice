class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Source and destination
        pair<int, int> src = {0, 0};
        pair<int, int> des = {n-1, n-1};

        // Initialize the queue for BFS  {dist , {i,j}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        // Initial push of the source node
        pq.push({grid[src.first][src.second], src});
        dist[src.first][src.second] = grid[src.first][src.second];

        // Directions for 4 possible movements
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1 , 0};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int i1 = it.second.first;
            int j1 = it.second.second;
            cout << "i1 " << i1 << " j1 " << j1 << " diff " <<diff <<endl;

            if (i1 == n - 1 && j1 == n - 1)
                return diff;

            for (int i = 0; i < 4; i++) {
                int nx = i1 + dx[i];
                int ny = j1 + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n ) {
                    int newEffort = max(grid[nx][ny], diff);
                    if(newEffort < dist[nx][ny]){
                        dist[nx][ny] = newEffort;
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }

        return 0;
        
    }
};
