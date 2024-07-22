class Solution {
public:
    int f(string s1, string s2, int i , int j, vector<vector<int>> dp){
        if(i == 0){
            return j;
        }
        if(j == 0){
            return i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ways = 0;
        if(s1[i-1] == s2[j-1]){
            ways = f(s1,s2,i-1,j-1, dp); 
        }
        else{
            ways = 1 + min(f(s1,s2,i,j-1, dp), min(f(s1,s2,i-1,j-1, dp), f(s1,s2,i-1,j, dp)));
        }

        return dp[i][j] = ways;

    }
    int minDistance_notoptimal(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int res = f(word1, word2, m, n, dp);

        return res;
        
    }


    // tabulation
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int dp[m+1][n+1];
        // set the base cases when either of the string is empty
        for(int i = 0; i <= m; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i <= n; i++){
            dp[0][i] = i;
        }
        // now do the same as recursion 
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{  // here i,j-1-> insertion in word1 
                       // i-1,j-> deletion in word1  
                       //i-1,j-1-> replace the last letter 
                    dp[i][j] =1 + min( dp[i][j-1] , min(dp[i-1][j-1], dp[i-1][j]));
                }
            }
        }
        return dp[m][n];
    }
    
};