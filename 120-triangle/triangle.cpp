class Solution {
public:
    int Triangle(vector<vector<int>>& grid, int n, int i, int j, vector<vector<int>>& dp){
        // base case (when we reach the last row just return what is there)
        if(i == n-1){
            return grid[n-1][j];
        }
        // if found return 
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //try all options either down or diagonal 
        int d = grid[i][j] + Triangle(grid, n, i+1, j, dp);
        int dg = grid[i][j] + Triangle(grid, n, i+1, j+1, dp);

        return dp[i][j] = min(d, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return Triangle(triangle, n, 0, 0, dp);
    }
};