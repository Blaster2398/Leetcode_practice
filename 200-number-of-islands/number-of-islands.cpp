class Solution {
public:
    void BFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;
        
        // Define the directions for moving up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            
            for (auto [dx, dy] : directions) {
                int nx = cx + dx;
                int ny = cy + dy;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int islandCount = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    BFS(grid, visited, i, j);
                    ++islandCount;
                }
            }
        }
        
        return islandCount;
    }
};