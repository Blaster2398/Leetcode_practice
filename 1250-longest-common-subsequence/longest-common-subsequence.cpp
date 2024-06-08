class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        int dp[m+1][n+1];
        // set the base cases when either of the string is empty
        for(int i = 0; i <= m; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i <= n; i++){
            dp[0][i] = 0;
        }
        // now do the same as recursion 
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
    // // let we are given with the lengths of the string as m ,n in the initial function call 
    // //ottherwise you have to  resize the string in every call 
    // vector<vector<int>> dp(m,vector<int>(n,-1));
    // int longestCommonSubsequence(string text1, string text2, int m, int n) {
    //     //if you already have the solution then just return 
    //     if(dp[m][n] != -1 ){
    //         return dp[m][n];  
    //     }
    //     // if not then calculate by recursion
    //     if(m == 0 || n == 0){
    //         dp[m][n] = 0;
    //     }
    //     // if both last are matching then subtract both m and n by  1 
    //     if(text1[m-1] == text2[n-1])
    //         dp[m][n] = 1+longestCommonSubsequence(text1, text2, m-1, n-1);
    //     }
    //     else{
    //         dp[m][n] =  max(longestCommonSubsequence(text1, text2, m-1, n),
    //                     longestCommonSubsequence(text1, text2, m, n-1));
    //     }

    //     return dp[m][n];
    // }
};