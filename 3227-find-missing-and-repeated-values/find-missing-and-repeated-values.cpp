class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int a = 0;

        // XOR all numbers from 1 to n*n
        for(int i = 1; i <= n * n; i++){
            a ^= i;
        }

        // XOR all elements of the grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a ^= grid[i][j];
            }
        }

        // Get rightmost set bit in `a`
        int set_bit = a & -a;
        int x = 0, y = 0;

        // Divide numbers into two groups based on `set_bit`
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j] & set_bit) {
                    x ^= grid[i][j];
                } else {
                    y ^= grid[i][j];
                }
            }
        }

        // Divide expected numbers (1 to n*n) into two groups
        for(int i = 1; i <= n * n; i++){
            if (i & set_bit) {
                x ^= i;
            } else {
                y ^= i;
            }
        }

        // Determine which is the missing and which is the repeated value
        int missing, repeating;
        int xCnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j] == x) {
                    xCnt++;
                }
            }
        }

        if (xCnt == 2) {  // `x` appears twice, so it's the repeating number
            repeating = x;
            missing = y;
        } else {          // `y` appears twice, so it's the repeating number
            repeating = y;
            missing = x;
        }

        return {repeating, missing};
    }
};
