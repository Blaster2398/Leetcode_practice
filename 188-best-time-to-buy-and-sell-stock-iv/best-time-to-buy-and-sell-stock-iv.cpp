class Solution {
public:
    int util(vector<int>& prices, int ind, int buy,vector<vector<vector<int>>>& dp, int maxd){
        // base cases 
        if(ind == prices.size()){
            return 0;
        }
        if(maxd == 0){
            return 0;
        }
        if(dp[ind][buy][maxd] != -1){
            return dp[ind][buy][maxd];
        }

        // steps
        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+ util(prices, ind+1, 0,dp,  maxd), 0 + util(prices, ind+1, 1,dp,  maxd));
        } else {
            profit = max(prices[ind] + util(prices, ind+1, 1,dp,  maxd-1), 0 + util(prices, ind+1, 0,dp,  maxd));
        }

        return dp[ind][buy][maxd] = profit;
    }
    int maxProfit_memo(int k, vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        // cout << util(prices, 0, 1, 2) << endl;
        return util(prices, 0, 1,dp,k);
    }




    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        

        // all base cases are already 0
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <=1; buy++){
                for(int maxd = 1; maxd <=k ; maxd++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[ind] + dp[ind+1][0][maxd] , 0 + dp[ind+1][1][maxd]);
                    }
                    else{
                        profit = max(prices[ind] + dp[ind+1][1][maxd-1], 0 + dp[ind+1][0][maxd]);
                    }
                    dp[ind][buy][maxd] = profit;
                }
            }
        }
        return dp[0][1][k];
    }




};