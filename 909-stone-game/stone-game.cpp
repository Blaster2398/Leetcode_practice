class Solution {
public:
    int util(vector<int>& piles , vector<vector<int>> & dp, int i, int j){
        if(i == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int chooseF = piles[i] + util(piles, dp, i+1, j);
        int chooseE = piles[j] + util(piles, dp, i, j-1);

        return dp[i][j] = max(chooseF, chooseE);
    }
    bool stoneGame_memo(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));

        int alice = util(piles, dp, 0, n-1);
        int bob = accumulate(piles.begin(), piles.end(), 0) - alice;

        return (alice > bob);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n,0));

        // int alice = util(piles, dp, 0, n-1);

        for(int i = n-2; i >= 0; i--){
            for(int j = 1; j < n; j++){
                int chooseF = piles[i] + util(piles, dp, i+1, j);
                int chooseE = piles[j] + util(piles, dp, i, j-1);

                dp[i][j] = max(chooseF, chooseE);
            }
        }

        int alice = dp[0][n-1];
        int bob = accumulate(piles.begin(), piles.end(), 0) - alice;
        

        return (alice > bob);
    }
};