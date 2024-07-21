class Solution {
public:
    int minInsertions_opt(string s) {
        int m = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        int n = t.length();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j ++){
                curr[j] = (s[i-1] == t[j-1]) ? 1 + prev[j-1] : max(prev[j] , curr[j-1]);
            }
            prev = curr;
        }

        return n - prev[n]; 
        
    }
    int minInsertions(string s) {
        int m = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        int n = t.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j ++){
                dp[i][j] = (s[i-1] == t[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i-1][j] , dp[i][j-1]);
            }
        }

        return n - dp[m][n]; 
        
    }
};