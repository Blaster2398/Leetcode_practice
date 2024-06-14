class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        // base case 
        

        for( int i = 0; i < m; i++){
            vector<int> curr (n,0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    curr[j] = 1;
                }
                else{
                    int up = (i>0) ? prev[j] :0 ;
                    int left = (j>0) ? curr[j-1] : 0 ;
                    curr[j] = up + left;
                }
            }
            prev =curr;
        }
        return prev[n-1] ;
    }
















    // int paths(int i, int j, vector<vector<int>> &dp){
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
    //     int up = paths(i-1, j, dp);
    //     int left = paths(i, j-1, dp);

    //     return dp[i][j] = up + left;

    // }
    // int uniquePaths_recursive(int m, int n) {
    //     vector<vector<int>> dp (m, vector<int> (n,-1));
    //     return paths(m-1, n-1, dp);
    // }





    // int uniquePaths(int m, int n) {
    //     int M_N = m+n-2;
    //     int N = n-1;
    //     int M = m-1;
    //     double ans = 1;

    //     // we need to find M_N ( C ) N
    //     for(int i =1  ; i <= M ;i++){
    //         ans = ans * (N+i)/i;
    //     }
    //     return int(ans);
    // }
    
};