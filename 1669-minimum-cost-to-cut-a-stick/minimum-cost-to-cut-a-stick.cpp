class Solution {
public:
    // memoisation
    int minCut(int i, int j, vector<int> & cuts,vector<vector<int>> & dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int miin = INT_MAX;
        for(int ind = i; ind <= j; ind++){

            int cost = cuts[j+1] - cuts[i-1] + minCut(i,ind-1,cuts,dp) + minCut(ind+1,j,cuts,dp);

            miin = min(miin, cost);
        }

        return dp[i][j] = miin;
    }
    int minCost_memo(int n, vector<int>& cuts) {
        // for the partition subproblem to work sort the array so that lft and right subproblem have the right cuts
        int c = cuts.size();
        
        cuts.push_back(n);
        cuts.push_back(0);

        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));   // added a dp array
        sort(cuts.begin(), cuts.end());

        return minCut(1, c, cuts, dp);
    }


    int minCost(int n, vector<int>& cuts) {
        // for the partition subproblem to work sort the array so that lft and right subproblem have the right cuts
        int c = cuts.size();
        
        cuts.push_back(n);
        cuts.push_back(0);

        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));   // added a dp array
        sort(cuts.begin(), cuts.end());

        for(int i = c; i >= 1; i--){
            for(int j = i; j <=c ;j++){
                int miin = INT_MAX;
                for(int ind = i; ind <= j; ind++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    miin = min(miin, cost);
                }
                dp[i][j] = miin;
            }
        }
        return dp[1][c];
    }







    // // recursion
    // int minCut(int i, int j, vector<int> & cuts){
    //     if(i>j){
    //         return 0;
    //     }
    //     int miin = INT_MAX;
    //     for(int ind = i; ind <= j; ind++){

    //         int cost = cuts[j+1] - cuts[i-1] + minCut(i,ind-1,cuts) + minCut(ind+1,j,cuts);

    //         miin = min(miin, cost);
    //     }

    //     return miin;
    // }
    // int minCost(int n, vector<int>& cuts) {
    //     // for the partition subproblem to work sort the array so that lft and right subproblem have the right cuts
    //     int c = cuts.size();

    //     cuts.push_back(n);
    //     cuts.push_back(0);

    //     sort(cuts.begin(), cuts.end());


    //     return minCut(1, c, cuts);
    // }
};