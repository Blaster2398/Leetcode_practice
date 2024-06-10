class Solution {
public:
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
                else{  // here i,j-1->insertion in word1 i-1,j->deletion in word1 and i-1,j-1->replace the last letter 
                    dp[i][j] =1 + min( dp[i][j-1] , min(dp[i-1][j-1], dp[i-1][j]));
                }
            }
        }
        return dp[m][n];
    }
    
};