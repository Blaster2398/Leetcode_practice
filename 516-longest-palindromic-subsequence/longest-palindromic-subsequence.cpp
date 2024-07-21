class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        int n = t.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        
        // base cases already handeled by 0
        for(int i = 0; i < m; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i < n; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j ++){
                dp[i][j] = (s[i-1] == t[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        return dp[m][n];
    }
};