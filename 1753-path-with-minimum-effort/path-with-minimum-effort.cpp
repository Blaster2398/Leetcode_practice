class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // Source and destination
        pair<int, int> src = {0, 0};
        pair<int, int> des = {n-1, n-1};

        // Initialize the queue for BFS
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        // Initial push of the source node
        pq.push({0, src});
        dist[0][0] = 0;

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

            if (i1 == n - 1 && j1 == m - 1)
                return diff;

            for (int i = 0; i < 4; i++) {
                int nx = i1 + dx[i];
                int ny = j1 + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m ) {
                    int newEffort = max(abs(heights[nx][ny]- heights[i1][j1]), diff);
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


