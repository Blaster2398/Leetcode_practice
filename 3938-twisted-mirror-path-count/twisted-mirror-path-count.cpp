class Solution {
public:
    int n, m;
    int mod = 1e9 + 7;
    int geek(int i, int j, int d, vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(i >= n || j >= m || i < 0 || j < 0)  return 0;
        if(i == n-1 && j == m-1) return 1;

        if(dp[i][j][d] != -1) return dp[i][j][d];

        int ways = 0;
        if(grid[i][j] == 0) ways = ((geek(i + 1, j, 1, grid, dp) % mod) + (geek(i, j+1, 0, grid, dp) % mod)) % mod;
        else{
            if(d == 0) ways = (geek(i + 1, j, 1, grid, dp) % mod);
            else ways = (geek(i, j + 1, 0, grid, dp) % mod);
        }

        return dp[i][j][d] = ways;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
       vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2 ,-1)));

       int count = (geek(0, 1, 0, grid, dp) % mod + geek(1, 0, 1, grid, dp) % mod) %mod;
       return count;
    }
};

