class Solution {
public:
    bool isAllStars(string& p, int j){
        for(int i = 0; i <= j; i++){
            if(p[i] != '*'){
                return false;
            }
        }
        return true;
    }
    bool f(string s, string p, int i , int j, vector<vector<bool>>& dp){
        // base cases 
        if(i < 0 && j < 0){
            return true;
        }
        if(i >= 0 && j < 0){
            return false;
        }
        if(i < 0 && j >= 0){
            return isAllStars(p, j);
        }
        
        // there are 2 cases either the string is matching or its not matching 
        bool res = true;
        if(s[i] == p[j]){
            res = f(s, p, i-1, j-1, dp);
        }
        else{
            // there are 3 cases 1. '?'  2.'*' 3.the character dont match 
            if(p[j] == '?'){
                res = f(s, p, i-1, j-1, dp);
            }
            else if(p[j] == '*'){
                res = (f(s, p, i, j-1, dp) || f(s, p, i-1, j, dp));
            }
            else{
                res = false;
            }
        }

        return dp[i][j] = res;
    }
    bool isMatch_memo(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        bool res = f(s, p, m-1, n-1, dp);
        return res;
    }


    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        // shift the inndexes by one place 
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        // base case
        dp[0][0]= true;

        for(int j = 1; j <= n; j++){
            dp[0][j] = isAllStars(p, j-1);
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                
                if((s[i-1] == p[j-1]) || (p[j-1] == '?')){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
                }
                
            }
        }

        return dp[m][n];
    }
};