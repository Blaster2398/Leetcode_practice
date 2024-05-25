class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price =INT_MAX;
        int max_profit=0;

        for(int i=0 ; i<size(prices);i++){
            if(buy_price<prices[i]){
                int profit = prices[i]-buy_price;
                max_profit = max(profit,max_profit);
            }
            else{
                buy_price = prices[i];
            }
        }
        return max_profit;
    }
};