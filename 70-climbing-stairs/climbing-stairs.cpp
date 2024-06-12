class Solution {
public:
    int util(int n, vector<int>& dp){
        
        if(n == 0){
            return 1;
        }
        
        if( dp[n] != -1){
            return dp[n];
        }
        int l = util(n-1,dp);
        int r = 0;
        if(n>1){
            int r = util(n-2,dp);
        }

        return dp[n] = l+r;
    }
    // int climbStairs(int n) {
    //     vector<int> dp(n+1,-1);
    //     return util(n,dp);
    // }


    
    int climbStairs(int n) {
        if(n<=1) return 1;

        vector<int>dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};