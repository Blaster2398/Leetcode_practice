class Solution {
public:
    // This is the memoization from n-1 -> 0 
    int geek(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid){
        if(i < 0 || j < 0) return 1e9;
        if(i == 0 && j == 0) return grid[0][0];

        if(dp[i][j] != -1) return dp[i][j];

        int cost = grid[i][j];
    
        int u = geek(i-1, j, dp, grid) + cost;
        int l = geek(i, j-1, dp, grid) + cost;

        return dp[i][j] = min(l,u); 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return geek(m-1, n-1, dp, grid);
    }
};