//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int lcsHelper(string& s1, string& s2, int i, int j, vector<vector<int>>& dp, int& maxLen) {
        // Base case: if we've reached the end of either string
        if (i == 0 || j == 0) return 0;
        
        // If we've already computed this subproblem, return the cached result
        if (dp[i][j] != -1) return dp[i][j];
        
        // Initialize current LCS to 0
        dp[i][j] = 0;
        
        // If characters match, extend the substring
        if (s1[i-1] == s2[j-1]) {
            dp[i][j] = 1 + lcsHelper(s1, s2, i-1, j-1, dp, maxLen);
            maxLen = max(maxLen, dp[i][j]);
        }
        
        // Always explore other possibilities
        lcsHelper(s1, s2, i-1, j, dp, maxLen);
        lcsHelper(s1, s2, i, j-1, dp, maxLen);
        
        return dp[i][j];
    }
    
    int longestCommonSubstr1 (string S1, string S2, int m, int n)
    {
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int maxLen = 0;
        int res  = lcsHelper(S1, S2, m, n, dp, maxLen);

        return maxLen;
    }
    
    
    
    // tabulation 
    int longestCommonSubstr (string S1, string S2, int m, int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // set the base cases when either of the string is empty
        for(int i = 0; i <= m; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i <= n; i++){
            dp[0][i] = 0;
        }
        
        int ans = 0;
        
        // now do the same as recursion 
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(S1[i-1] == S2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends