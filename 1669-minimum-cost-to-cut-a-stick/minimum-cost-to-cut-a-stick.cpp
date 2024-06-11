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
    int minCost(int n, vector<int>& cuts) {
        // for the partition subproblem to work sort the array so that lft and right subproblem have the right cuts
        int c = cuts.size();
        
        cuts.push_back(n);
        cuts.push_back(0);

        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        sort(cuts.begin(), cuts.end());


        return minCut(1, c, cuts, dp);
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