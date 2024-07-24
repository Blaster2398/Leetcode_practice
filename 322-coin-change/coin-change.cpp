#include <bits/stdc++.h>
class Solution {
public:
    int util(vector<int>& coins, int amount, int ind, vector<vector<int>> & dp){
        if(amount == 0){
            return 0;
        }
        if(ind == coins.size()){
            return INT_MAX - 1;
        }
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }
        int take = INT_MAX -1;
        int not_take = util(coins, amount, ind + 1, dp);;
        if(coins[ind] <= amount){
            int sub_res = util(coins, amount - coins[ind], ind, dp);
            if(sub_res != INT_MAX - 1){
                take = 1 + sub_res;
            }
        }
        return dp[ind][amount] = min(take, not_take);

    }
    

    // recursive
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size() +1, vector<int>(amount+ 1, -1));
        int res = util(coins, amount, 0, dp);

        if(res == INT_MAX - 1){
            return -1;
        }
        else{
            return res;
        }
    }
};