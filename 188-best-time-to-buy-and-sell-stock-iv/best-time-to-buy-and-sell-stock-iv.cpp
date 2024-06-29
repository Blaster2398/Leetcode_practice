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
    int maxProfit(int k, vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        // cout << util(prices, 0, 1, 2) << endl;
        return util(prices, 0, 1,dp,k);
    }




};