#include <bits/stdc++.h>
class Solution {
public:
    int util(vector<int>& coins, int amount, int ind, vector<vector<int>> & dp){
        //base case
        if(amount == 0){
            return 0;
        }
        if(ind == coins.size()){
            return INT_MAX - 1;
        }

        // is present return 
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }

        //stuff to do 
        int take = INT_MAX -1;
        int not_take = util(coins, amount, ind + 1, dp);
        if(coins[ind] <= amount){
            int sub_res = util(coins, amount - coins[ind], ind, dp);
            if(sub_res != INT_MAX - 1){
                take = 1 + sub_res;
            }
        }
        return dp[ind][amount] = min(take, not_take);

    }

    // recursive
    int coinChange1(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size() +1, vector<int>(amount+ 1, -1));
        int res = util(coins, amount, 0, dp);

        if(res == INT_MAX - 1){
            return -1;
        }
        else{
            return res;
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size() +1, vector<int>(amount+ 1, 0));
        for(int i = 0; i <= amount; i++){
            dp[coins.size()][i] = INT_MAX - 1;
        }
        for(int ind = coins.size() -1; ind >= 0; ind--){
            for(int amt = 1; amt <= amount; amt++){
                int take = INT_MAX -1;
                int not_take = dp[ind+1][amt];
                if(coins[ind] <= amt){
                    int sub_res = dp[ind][amt - coins[ind]];
                    if(sub_res != INT_MAX - 1){
                        take = 1 + sub_res;
                    }
                }
                dp[ind][amt] = min(take, not_take);
            }
        }

        return (dp[0][amount] != INT_MAX-1)? dp[0][amount] : -1;
    }

};