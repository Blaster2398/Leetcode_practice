class Solution {
public:
    int n, m;
    int geek(int i, int j, vector<vector<int>> & dp, vector<vector<int>> & d){
        // base case 
        if(i >= n || j >= m) return INT_MAX;
        if(i == n-1 && j == m-1) return max(1, 1 - d[i][j]);    // when we reach the end we should have min 1 energy 
        if(dp[i][j] != -1) return dp[i][j];

        // traverse to right and down 
        int right = geek(i, j + 1, dp, d);
        int down = geek(i+1 , j , dp, d);
        // return the min health needed to reach this point safely

        int need = min(down, right) - d[i][j];
        return dp[i][j] = max(1,need);
    }
    int calculateMinimumHP(vector<vector<int>>& d) {
        n = d.size();
        m = d[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return geek(0, 0, dp, d);
    }
};