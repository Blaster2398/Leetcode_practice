class Solution {
public:
    // recursive + memo
    int util(vector<int>& prices, int ind, int buy,vector<vector<int>>& dp){
        // base cases 
        if(ind >= prices.size()){
            return 0;
        }
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        // steps
        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+ util(prices, ind+1, 0, dp), 0 + util(prices, ind+1, 1, dp));
        } else {
            profit = max(prices[ind] + util(prices, ind+2, 1, dp), 0 + util(prices, ind+1, 0, dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit_memo(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));
        return util(prices, 0, 1, dp);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front1(2,0), curr(2,0), front2(2,0);

        // //base case
        // front1[0] = front1[1] = 0;

        // as it is top doun go from n-1 to 0
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <=1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind]+ front1[0], 0 + front1[1]);
                } else {
                    profit = max(prices[ind] + front2[1], 0 + front1[0]);
                }
                curr[buy] = profit;
            }
            front2 = front1;
            front1 = curr;
        }
        return curr[1];
    }

    // TAbulatin
    int maxProfit_tab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        //base case
        dp[n][0] = dp[n][1] = 0;

        // as it is top doun go from n-1 to 0
        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <=1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind]+ dp[ind+1][0], 0 + dp[ind+1][1]);
                } else {
                    profit = max(prices[ind] +((ind+2 >= n) ? 0 : dp[ind+2][1]), 0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};