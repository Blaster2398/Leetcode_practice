class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buyPrice = prices[0];
        for(int i = 0; i< prices.size(); i++){
            if(buyPrice < prices[i]){
                int profit = prices[i] - buyPrice;
                maxProfit += profit;
                buyPrice = prices[i];
            }
            else{
                buyPrice = prices[i];
            }
        }
        return maxProfit;
    }
};