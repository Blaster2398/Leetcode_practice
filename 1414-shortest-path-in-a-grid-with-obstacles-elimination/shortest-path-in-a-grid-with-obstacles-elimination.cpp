class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(k+1, 0)));
        queue<tuple<int,int,int,int>> q; // this will store i, j, path, obstaclesleft

        if(grid[0][0] == 1){
            q.push({0,0,0,k-1});
            vis[0][0][k-1] = 1;
        }
        else{
            q.push({0,0,0,k});
            vis[0][0][k] = 1;
        }
        
        while(!q.empty()){
            auto[i, j, dis, wall] = q.front();
            q.pop();

            if(i == n-1 && j == m-1) return dis;

            vector<int> dx = {0,0,1,-1};
            vector<int> dy = {1,-1,0,0};
            for(int k = 0; k < 4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && nj >= 0 && ni < n && nj < m ){
                    if(grid[ni][nj] == 1  && wall > 0 && !vis[ni][nj][wall-1]){
                        q.push({ni, nj, dis+1, wall-1});
                        vis[ni][nj][wall-1] = 1;
                    }
                    else if(grid[ni][nj] == 0 && !vis[ni][nj][wall]){
                        q.push({ni, nj, dis+1, wall});
                        vis[ni][nj][wall] = 1;
                    }
                }
            }
        }
        return -1;
    }
};