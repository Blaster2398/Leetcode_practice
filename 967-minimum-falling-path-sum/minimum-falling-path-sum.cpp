#define MAX 1e9
class Solution {
// private:
//     int fall(vector<vector<int>>& matrix, int n, int i, int j, vector<vector<int>>& dp){
//         //out of bound and base cases 
//         if(j < 0 || j >= n){
//             return MAX;
//         }
//         if(i == 0){
//             return matrix[i][j];
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         int lu = matrix[i][j] + fall(matrix, n, i-1, j-1, dp);
//         int u = matrix[i][j] + fall(matrix, n, i-1, j, dp);
//         int ru = matrix[i][j] + fall(matrix, n, i-1, j+1, dp);

//         return dp[i][j] = min(lu, min(u, ru));
//     }
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         if (n == 0) return 0; // Edge case: empty matrix

//         vector<vector<int>> dp(n, vector<int>(n,-1));
//         int mini = MAX;
//         for(int i =0 ; i< n; i++){
//             int sum = fall(matrix, n ,n-1, i, dp);
//             mini = min(mini,sum);
//         }

//         return mini;
//     }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        
        // base case when it reaches i= 0 fill the dpp
        for(int j = 0; j <n; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                    int lu = matrix[i][j] + ((j>0) ? dp[i-1][j-1] : MAX);
                    int u = matrix[i][j] + dp[i-1][j];
                    int ru = matrix[i][j] + ((j<n-1) ? dp[i-1][j+1] : MAX);
                
                dp[i][j] = min(lu, min(u, ru));
            }
        }

        int mini = MAX;
        for(int j = 0; j < n; j++){
            mini = min(dp[n-1][j], mini);
        }
        return mini;
    }
};