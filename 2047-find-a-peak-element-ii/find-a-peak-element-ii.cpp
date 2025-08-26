class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i = 0, j = 0;
        while(i >= 0 && j >= 0 && i < n && j < m){
            int up = (i == 0) ? INT_MIN :  mat[i-1][j];
            int down = (i == n-1) ? INT_MIN : mat[i+1][j];
            int left = (j == 0) ? INT_MIN : mat[i][j-1];
            int right = (j == m-1) ? INT_MIN : mat[i][j+1];
            int curr = mat[i][j];
            if(curr > up && curr > down && curr > left && curr > right) return {i , j};
            else if(curr < up) i--;
            else if(curr < down) i++;
            else if(curr < left) j--;
            else j++;
        }

        return {i, j};
    }
};