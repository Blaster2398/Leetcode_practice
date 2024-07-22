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
    int numDistinct1(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp (m+1, vector<int>(n+1, -1));
        int res = util(str1, str2, m, n, dp);
        return res;    

    }


    // tabulation
    int numDistinct2(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        
        // Base case: empty t string can be formed in one way
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return (dp[m][n] > INT_MAX) ? INT_MAX : (int)dp[m][n];
    }


    //space opt
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        const unsigned long long MOD = 1e9 + 7;
        
        vector<unsigned long long> prev(n+1, 0);
        vector<unsigned long long> curr(n+1, 0);
        
        // Base case: empty t string can be formed in one way
        prev[0] = curr[0] = 1;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1]) {
                    curr[j] = (prev[j-1] + prev[j]) % MOD;
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        
        return prev[n];
    
    }
};