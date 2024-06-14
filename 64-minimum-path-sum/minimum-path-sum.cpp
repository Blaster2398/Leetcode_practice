class Solution {
public:
    int paths(int i, int j, vector<vector<int>> &dp,vector<vector<int>>& grid){
        //base cases 
        if(i == 0 && j == 0){
            return grid[0][0];
        }
        if(i<0 || j<0){   // out of bounds will return
                          // a big value 
            return 1e9;
        }
        // check is ans is already present 
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = grid[i][j] + paths(i-1, j, dp, grid);
        int left = grid[i][j] + paths(i, j-1, dp, grid);

        return dp[i][j] = min(up,left);

    }
    int minPathSum_recursive(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp (m, vector<int> (n,-1));
        return paths(m-1, n-1, dp, grid);
    }

     // tabulation
    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp (m, vector<int> (n,0));

        for( int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(i == 0 && j == 0){
                    dp[i][j] = grid[0][0];
                }
                
                else{
                    int up = (i-1>=0) ? grid[i][j]+dp[i-1][j] : 1e9 ;
                    int left = (j-1>=0) ? grid[i][j]+dp[i][j-1] : 1e9 ;
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[m-1][n-1] ;
    }

};