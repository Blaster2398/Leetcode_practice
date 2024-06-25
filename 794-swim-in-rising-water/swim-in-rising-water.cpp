class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Source and destination
        pair<int, int> src = {0, 0};
        pair<int, int> dest = {n-1, n-1};

        // Initialize the queue for BFS {time, {x, y}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> time(n, vector<int>(n, 1e9));
        
        // Initial push of the source node
        pq.push({grid[src.first][src.second], src});
        time[src.first][src.second] = grid[src.first][src.second];

        // Directions for 4 possible movements
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int currTime = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if (x == n - 1 && y == n - 1)
                return currTime;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int newTime = max(grid[nx][ny], currTime);
                    if (newTime < time[nx][ny]) {
                        time[nx][ny] = newTime;
                        pq.push({newTime, {nx, ny}});
                    }
                }
            }
        }

        return time[n-1][n-1];
    }
};
