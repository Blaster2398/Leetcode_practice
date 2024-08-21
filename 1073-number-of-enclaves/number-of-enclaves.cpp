class Solution {
public:
    // int BFS(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, int &flag) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     queue<pair<int, int>> q;
    //     q.push({i, j});
    //     visited[i][j] = true;
    //     int cnt = 1;

    //     if(i == 0 || j == 0 || i == m-1 || j == n-1){
    //         flag = 1;
    //     }

    //     // Directions for moving in the grid (left, up, right, down)
    //     vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        
    //     while (!q.empty()) {
    //         auto [ci, cj] = q.front();
    //         q.pop();
            
    //         for (auto [di, dj] : directions) {
    //             int ni = ci + di;
    //             int nj = cj + dj;
                
    //             if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1 && !visited[ni][nj]) {
    //                 visited[ni][nj] = true;
    //                 cnt++;
    //                 q.push({ni, nj});
    //             }
                
    //             if ((ni == 0 || ni == m-1 || nj == 0 || nj == n-1 ) ) {  /*&& visited[ni][nj]*/
    //                 flag = 1;
    //             }
    //         }
    //     }
    //     cout << "flag " <<flag <<endl;
    //     return flag == 1 ? 0 : cnt;
    // }


    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (!visited[i][j] && grid[i][j] == 1) {
        //             cout << "bfs called for " << i << " " << j <<endl;
        //             int flag = 0;
        //             int cnt = BFS(grid, i, j, visited, flag);
        //             count += cnt;
        //         }
        //     }
        // }

        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1){
                q.push({i,0});
            }
            if(grid[i][n-1] == 1){
                q.push({i,n-1});
            }
        }
        
        for(int i = 0; i < n; i++){
            if(grid[0][i] == 1){
                q.push({0,i});
            }
            if(grid[m-1][i] == 1){
                q.push({m-1,i});
            }
        }


        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            grid[i][j] = 0;

            vector<pair<int,int>> dx = {{0,1}, {0,-1}, {1,0}, {-1,0}};

            for(auto [di,dj] : dx){
                int ni = i + di;
                int nj = j + dj;

                if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1){
                    grid[ni][nj] = 0;
                    q.push({ni,nj});
                }
            }
        }

        for(int i = 0; i< m; i++){
            for(int j = 0;j < n; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
        
    }
};

