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

    // there is O(n) solution also 
    int maxProfit(vector<int>& prices) {
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
