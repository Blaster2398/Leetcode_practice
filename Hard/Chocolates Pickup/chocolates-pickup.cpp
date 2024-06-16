//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  const int MIN = -1e8;  
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        //base case 
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
         for (int i = n-2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = MIN;
                    for (int dA = -1; dA <= 1; dA++) {
                        for (int dB = -1; dB <= 1; dB++) {
                            int score = MIN;
                            int nj1 = j1 + dA;
                            int nj2 = j2 + dB;
                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                                if (j1 == j2) {
                                    score = grid[i][j1] + dp[i+1][nj1][nj2];
                                } else {
                                    score = grid[i][j1] + grid[i][j2] + dp[i+1][nj1][nj2];
                                }
                            }
                            maxi = max(maxi, score);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
        
        
    }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
    int f(vector<vector<int>>& grid, int n , int m, int i1, int j1, int j2, vector<vector<vector<int>>> &dp){
        // base case 
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
            return MIN;
        }
        if(i1 == n-1){
            // 2 cases (i) they reach to the same cell (ii) they reach to diff cell 
            if( j1 == j2 ) return grid[i1][j1];
            else           return grid[i1][j1] + grid[i1][j2];
        }
        if(dp[i1][j1][j2] != -1){
            dp[i1][j1][j2];
        }
        //doing sutffs 
        int maxi = MIN;
        for(int dA = -1; dA < 2; dA ++){
            for(int dB = -1; dB < 2; dB ++){
                int score = 0;
                if(j1 == j2) score = grid[i1][j1] + f(grid, n ,m , i1 + 1, j1+ dA, j2+ dB, dp);
                else score = grid[i1][j1] + grid[i1][j2] +  f(grid, n ,m , i1 + 1, j1+ dA, j2+ dB, dp);
                
                maxi = max(maxi , score);
            }
        }
        
        return dp[i1][j1][j2] = maxi;
    }
    int solve_recursive(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(grid, n, m, 0, 0, m-1, dp);
    }
    
};












//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends