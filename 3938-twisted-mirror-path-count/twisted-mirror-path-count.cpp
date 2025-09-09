class Solution {
public:
    int n, m;
    const int MOD = 1e9 + 7;

    int dfs(int i, int j, int d, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (i < 0 || j < 0 || i >= n || j >= m) return 0;
        if (i == n - 1 && j == m - 1) return 1;
        if (dp[i][j][d] != -1) return dp[i][j][d];

        long long ways = 0;
        if (grid[i][j] == 0) {
            ways += dfs(i, j + 1, 0, grid, dp);
            ways += dfs(i + 1, j, 1, grid, dp);
        } else {
            if (d == 0) ways += dfs(i + 1, j, 1, grid, dp);
            else ways += dfs(i, j + 1, 0, grid, dp);
        }

        return dp[i][j][d] = ways % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));

        long long ans = 0;
        ans += dfs(0, 1, 0, grid, dp);
        ans += dfs(1, 0, 1, grid, dp);

        return ans % MOD;
    }
};
