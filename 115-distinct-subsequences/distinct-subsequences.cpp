class Solution {
public:
    int util(string str1, string str2, int i, int j, vector<vector<int>>& dp){
        // base cases 
        if(j == 0){
            return 1;
        }

        if(i == 0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // stuff to do 
        int ways = 0;
        if(str1[i-1] == str2[j-1]){
            ways = util(str1, str2, i-1, j-1, dp) + util(str1, str2, i -1, j, dp);
        }
        else{
            ways = util(str1, str2, i -1, j, dp);
        }

        return dp[i][j] = ways;
    }
    int numDistinct(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp (m+1, vector<int>(n+1, -1));
        int res = util(str1, str2, m, n, dp);
        return res;    

    }
};