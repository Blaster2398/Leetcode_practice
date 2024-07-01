class Solution {
public:
    // // recursion
    // int f(vector<int>& arr, int k, int i){
    //     // base case 
    //     if(i == arr.size()) return 0;


    //     // do some stuff
    //     int maxi = INT_MIN;
    //     int len = 0;
    //     int maxele = arr[i];
    //     int range = min(i + k, (int)arr.size());
    //     for(int j = i; j < range; j++){
    //         len++;
    //         maxele = max(maxele, arr[j]);
    //         int sum = (len * maxele) + f(arr, k, j+1);
    //         maxi = max(maxi, sum);
    //     }
    //     return maxi;
    // }
    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     return f(arr, k, 0);
    // }



    int memoization(vector<int>& arr, int k, int i, vector<int>& dp) {
        if (i >= arr.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int currMax = 0, best = 0;
        for (int j = 1; j <= k && i + j <= arr.size(); j++) {
            currMax = max(currMax, arr[i + j - 1]);
            best = max(best, currMax * j + memoization(arr, k, i + j, dp));
        }

        return dp[i] = best;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // Uncomment one of the following approaches:
        vector<int> dp (arr.size(), -1);
        return memoization(arr, k, 0, dp);
        // return tabulation(arr, k);
    }



    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     vector<int> dp( arr.size() , -1);
    //     return f(arr, k, 0, dp);
    // }
};