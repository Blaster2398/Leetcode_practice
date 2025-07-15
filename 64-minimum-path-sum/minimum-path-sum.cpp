class Solution {
public:
    // this is the tabulation
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++){
            vector<int> curr(n , 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) curr[j] = grid[0][0];
                else{
                    int cost = grid[i][j];
                    int u = ( i > 0 ) ? prev[j] + cost : INT_MAX;
                    int l = ( j > 0 ) ? curr[j-1] + cost : INT_MAX;

                    curr[j] = min(l,u); 
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};