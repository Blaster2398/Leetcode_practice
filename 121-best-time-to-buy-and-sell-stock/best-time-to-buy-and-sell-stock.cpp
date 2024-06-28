class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = prices[0];
        int profit = 0;
        for(int i = 0; i < prices.size(); i++){
            profit = max(profit, prices[i] - buy_price);
            buy_price = min(buy_price, prices[i]);
        }
        return profit;
    }







    // int maxProfit(vector<int>& prices) {
    //     int buy_price =INT_MAX;
    //     int max_profit=0;

    //     for(int i=0 ; i<prices.size();i++){
    //         if(buy_price<prices[i]){
    //             int profit = prices[i]-buy_price;
    //             max_profit = max(profit,max_profit);
    //         }
    //         else{
    //             buy_price = prices[i];
    //         }
    //     }
    //     return max_profit;
    // }
};