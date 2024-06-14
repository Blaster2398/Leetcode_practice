class Solution {
public:
    int paths(int i, int j, vector<vector<int>> &dp,vector<vector<int>>& grid){
        //base cases 
        if(i == 0 && j == 0 && grid[i][j] != 1){
            return 1;
        }
        
        if(i<0 || j<0){   // out of bounds 
            return 0;
        }
        if(grid[i][j] == 1){
            return 0;
        }
        // check is ans is already present 
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = paths(i-1, j, dp, grid);
        int left = paths(i, j-1, dp, grid);

        return dp[i][j] = up + left;
    }
        

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp (m, vector<int> (n,-1));
        return paths(m-1, n-1, dp, obstacleGrid);
    }
};