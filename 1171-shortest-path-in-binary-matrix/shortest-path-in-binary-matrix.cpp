class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // Source and destination
        pair<int, int> src = {0, 0};
        pair<int, int> des = {n-1, n-1};

        // Initialize the queue for BFS
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        // Initial push of the source node
        q.push({1, src});
        dist[0][0] = 1;

        // Directions for 8 possible movements
        vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
        vector<int> dy = {1, 1, 0, -1, -1 , -1, 0, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int i1 = it.second.first;
            int j1 = it.second.second;

            if (i1 == des.first && j1 == des.second) return dis;

            for (int i = 0; i < 8; i++) {
                int nx = i1 + dx[i];
                int ny = j1 + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && dis + 1 < dist[nx][ny]) {
                    dist[nx][ny] = 1 + dis;
                    q.push({1 + dis, {nx, ny}});
                }
            }
        }

        return -1;
    }
};