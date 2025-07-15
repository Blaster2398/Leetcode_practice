class Solution {
public:
    // this is the tabulation
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[0][0];
                else{
                    int cost = grid[i][j];
                    int u = ( i > 0 ) ? dp[i-1][j] + cost : INT_MAX;
                    int l = ( j > 0 ) ? dp[i][j-1] + cost : INT_MAX;

                    dp[i][j] = min(l,u); 
                }
            }
        }
        return dp[m-1][n-1];
    }
};