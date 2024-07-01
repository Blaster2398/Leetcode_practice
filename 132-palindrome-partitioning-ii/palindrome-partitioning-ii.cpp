class Solution {
public:
    bool isPal(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int f(string s, int i, int n, vector<int>& dp){
        if(i == n){
            return -1;
        }

        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPal(s, i, j)){
                int count = 1 + f(s, j+1, n, dp);
                mini = min(mini, count);
            }
        }
        return dp[i] = mini;
    }
    int minCut_memo(string s) {
        int n = s.size();
        vector<int> dp(n, -1);  // only changing parameter is index i
        return f(s, 0, n, dp);
    }


    // recursion 
    int f_rec(string s, int i, int n){
        if(i == n){
            return -1;//this is fpr the last partition as we dont need it 
            //ex- ABC will have A|B|C|  3 partition if we dont subtract -1 
        }
        int mini = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPal(s, i, j)){
                int count = 1 + f_rec(s, j+1, n);
                mini = min(mini, count);
            }
        }
        return mini;
    }
    int minCut_recursive(string s) {
        int n = s.size();
        return f_rec(s, 0, n);
    }

    bool isPald(string& str, int s, int e, vector<vector<int>>& isPaldp) {
        if (s >= e) return true; // Correct base case for palindrome check

        if (isPaldp[s][e] != -1) return isPaldp[s][e];

        if (str[s] == str[e]) {
            return isPaldp[s][e] = isPald(str, s + 1, e - 1, isPaldp);
        } else {
            return isPaldp[s][e] = false;
        }
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, INT_MAX);  // only changing parameter is index i
        vector<vector<int>> isPaldp(n, vector<int>(n, -1));
        
        // Precompute the palindrome status
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                isPald(s, i, j, isPaldp);
            }
        }


        dp[n] = -1;
        for(int i = n-1; i >= 0; i--){
           int mini = INT_MAX;
            for(int j = i; j < n; j++){
                if(isPald(s, i, j, isPaldp)){
                    int count = 1 + dp[j+1];
                    mini = min(mini, count);
                }
            }
            dp[i] = mini; 
        }
        return dp[0];

    }
};