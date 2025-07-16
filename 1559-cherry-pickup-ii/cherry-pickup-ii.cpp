class Solution {
public:
    // here is the drect tabulation code for this question the memo is on tuf 
    int cherryPickup(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

        // base case fill all the elements in the last row fix i = m-1
        for(int j1 = 0; j1 < n; j1++){
            for(int j2 = 0; j2 < n; j2++){
                if(j1 == j2) dp[m-1][j1][j2] = g[m-1][j1];
                else dp[m-1][j1][j2] = g[m-1][j1] + g[m-1][j2];
            }
        }

        // now go from the 2nd last ro to the top
        for(int i = m-2; i >= 0; i--){
            for(int j1 = 0; j1 < n; j1++){
                for(int j2 = 0; j2 < n; j2++){
                    
                    int maxi = -1e9;
                    for(int d1 = -1; d1 <= 1; d1++){
                        for(int d2 = -1; d2 <= 1; d2++){
                            int nj1 = j1 + d1;
                            int nj2 = j2 + d2;

                            if(nj1 >= 0 && nj2 >= 0 && nj1 < n && nj2 < n){
                                int score = 0;
                                if(j1 == j2) score = g[i][j1] + dp[i+1][nj1][nj2];
                                else score = g[i][j1] + g[i][j2] + dp[i+1][nj1][nj2];
                                maxi = max(maxi, score);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;

                }
            }
        }
        return dp[0][0][n-1];
    }
};