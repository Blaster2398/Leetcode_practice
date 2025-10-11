class Solution {
public:
    int geek(int ind, int target, int n, vector<int>& arr, vector<vector<int>>& dp)
    {
        if(target == 0) return 0;
        if(ind >= n) return 1e8;

        if(dp[ind][target] != -1) return dp[ind][target];

        int ntake = geek(ind+1, target, n, arr, dp);
        int take = (target >= arr[ind]) ? 1 + geek(ind, target - arr[ind], n, arr, dp) : INT_MAX;
        return dp[ind][target] = min(take, ntake);
    }
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i <= sqrt(n); i++){
            squares.push_back(i*i);
        }

        // now this is target sum from dp 
        int n1 = squares.size();
        vector<vector<int>> dp(n1+1, vector<int>(n+1, -1));
        return geek(0, n, n1, squares, dp);
    }
};