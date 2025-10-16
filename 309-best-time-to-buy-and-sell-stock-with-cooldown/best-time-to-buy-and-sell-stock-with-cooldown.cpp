class Solution {
public:
    vector<vector<int>> dp;
    vector<int> p;
    int geek(int i, int sell){
        if(i >= p.size()) return 0;

        if(dp[i][sell] != -1) return dp[i][sell];

        int ways = 0;
        if(sell == 0){
            // we can buy
            ways = max(geek(i+1, 0) , -p[i] + geek(i+1, 1));
        }
        else{
            // we can sell
            ways = max(geek(i+1, 1) , p[i] + geek(i+2, 0));
        }

        return dp[i][sell] = ways;
    }
    int maxProfit(vector<int>& prices) {
        p = prices;
        dp.assign(p.size(), vector<int>(2, -1));
        return geek(0, 0);
    }
};