class Solution {
public:
    // int paths(int i, int j, vector<vector<int>> &dp,vector<vector<int>>& grid){
    //     //check if its a valid cell and has a obstacle 
    //     if(i>=0 && j>=0 && grid[i][j] == 1){
    //         return 0;
    //     }
    //     //base cases 
    //     if(i == 0 && j == 0){
    //         return 1;
    //     }
    //     if(i<0 || j<0){   // out of bounds 
    //         return 0;
    //     }
        
    //     // check is ans is already present 
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int up = paths(i-1, j, dp, grid);
    //     int left = paths(i, j-1, dp, grid);

    //     return dp[i][j] = up + left;
    // }
        

    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();

    //     vector<vector<int>> dp (m, vector<int> (n,-1));
    //     return paths(m-1, n-1, dp, obstacleGrid);
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp (m, vector<int> (n,0));

        for( int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(i == 0 && j == 0 && obstacleGrid[i][j] != 1){
                    dp[i][j] = 1;
                }
                
                else if(obstacleGrid[i][j] != 1){
                    int up = (i-1>=0) ? dp[i-1][j] :0 ;
                    int left = (j-1>=0) ? dp[i][j-1] : 0 ;
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1] ;
    }
    
};