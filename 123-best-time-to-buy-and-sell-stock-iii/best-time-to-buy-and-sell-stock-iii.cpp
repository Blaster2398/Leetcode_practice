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
    int maxProfit_memo(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        // cout << util(prices, 0, 1, 2) << endl;
        return util(prices, 0, 1,dp ,2);
    }








    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> after (2, vector<int>(3, 0));
        vector<vector<int>> curr (2, vector<int>(3, 0));
        
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int maxd = 1; maxd <= 2; maxd++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[ind]+ after[0][maxd], 0 + after[1][maxd]);
                    } else {
                        profit = max(prices[ind] + after[1][maxd-1], 0 + after[0][maxd]);
                    }

                    curr[buy][maxd] = profit;
                }
            }
            after = curr;
        }
        return after[1][2];
    }








    int maxProfit_tabulation(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        

        //// as it is already 0 no use of wrting these
        // // when ind == n buy and cap can be any thing
        // for(int i = 0; i < 2; i++){
        //     for(int j = 0; j < 3; j++){
        //         dp[n][i][j] = 0;
        //     }
        // }
        // // when cap == 0 then buy and n can be any thing
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < 2;j++){
        //         dp[i][j][0] = 0;
        //     }
        // }

        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int maxd = 1; maxd <= 2; maxd++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[ind]+ dp[ind+1][0][maxd], 0 + dp[ind+1][1][maxd]);
                    } else {
                        profit = max(prices[ind] + dp[ind+1][1][maxd-1], 0 + dp[ind+1][0][maxd]);
                    }

                    dp[ind][buy][maxd] = profit;
                }
            }
        }
        return dp[0][1][2];
    }











    // there is O(n) solution also 
    int maxProfit_opt(vector<int>& prices) {
        int f1 = -prices[0], f2 = 0, f3 = -prices[0], f4 = 0;
        for (int i = 1; i < prices.size(); ++i) {
            f1 = max(f1, -prices[i]);
            f2 = max(f2, f1 + prices[i]);
            f3 = max(f3, f2 - prices[i]);
            f4 = max(f4, f3 + prices[i]);
        }
        return f4;
    }
    
};
