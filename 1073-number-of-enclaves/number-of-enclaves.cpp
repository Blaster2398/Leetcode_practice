class Solution {
public:
   

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;

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

